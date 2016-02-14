//
//  GB2ShapeCache-x.cpp
//
//  Loads physics sprites created with https://www.codeandweb.com/physicseditor
//  To be used with cocos2d-x
//
//  Generic Shape Cache for box2d
//
//  Created by Thomas Broquist
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#include "GB2ShapeCache-x.h"
#include "box2d/Box2D.h"
#include "CCNS.h"

#include "GameMacro.h"

USING_NS_CC;

/**
 * Internal class to hold the fixtures
 */
class FixtureDef {
public:
    FixtureDef()
    : next(NULL) {}
    
    ~FixtureDef() {
        delete next;
        delete fixture.shape;
    }
    
    FixtureDef *next;
    b2FixtureDef fixture;
    int callbackData;
};

class BodyDef {
public:
    BodyDef()
    : fixtures(NULL) {}
    
    ~BodyDef() {
        if (fixtures)
            delete fixtures;
    }
    
    FixtureDef *fixtures;
    Point anchorPoint;
};

static GB2ShapeCache *_sharedGB2ShapeCache = NULL;

GB2ShapeCache* GB2ShapeCache::sharedGB2ShapeCache(void) {
    if (!_sharedGB2ShapeCache) {
        _sharedGB2ShapeCache = new GB2ShapeCache();
        _sharedGB2ShapeCache->init();
    }
    
    return _sharedGB2ShapeCache;
}

bool GB2ShapeCache::init() {
    return true;
}

void GB2ShapeCache::reset() {
    std::map<std::string, BodyDef *>::iterator iter;
    for (iter = shapeObjects.begin() ; iter != shapeObjects.end() ; ++iter) {
        delete iter->second;
    }
    shapeObjects.clear();
}

void GB2ShapeCache::addFixturesToBody(b2Body *body, const std::string &shape) {
    std::map<std::string, BodyDef *>::iterator pos = shapeObjects.find(shape);
    assert(pos != shapeObjects.end());
    
    BodyDef *so = (*pos).second;

    FixtureDef *fix = so->fixtures;
    while (fix) {
        body->CreateFixture(&fix->fixture);
        fix = fix->next;
    }
}

cocos2d::Point GB2ShapeCache::anchorPointForShape(const std::string &shape) {
    std::map<std::string, BodyDef *>::iterator pos = shapeObjects.find(shape);
    assert(pos != shapeObjects.end());
    
    BodyDef *bd = (*pos).second;
    return bd->anchorPoint;
}

bool GB2ShapeCache::addShapesWithFile(const std::string &plist) {
    ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(plist);
    if (dict.empty())
    {
        // plist file not found
        return false;
    }
    
    ValueMap &metadata = dict["metadata"].asValueMap();
    int format = metadata["format"].asInt();
    if (format != 1)
    {
        CCASSERT(format == 1, "format not supported!");
        return false;
    }
    
    float ptmRatio = metadata["ptm_ratio"].asFloat() * BOX2D_PTM_RATIO;
    
    ValueMap &bodydict = dict.at("bodies").asValueMap();
    b2Vec2 vertices[b2_maxPolygonVertices];
    
    for (auto iter = bodydict.cbegin(); iter != bodydict.cend(); ++iter)
    {
        const ValueMap &bodyData = iter->second.asValueMap();
        std::string bodyName = iter->first;
        BodyDef *bodyDef = new BodyDef();
        bodyDef->anchorPoint          = PointFromString(bodyData.at("anchorpoint").asString());
        const ValueVector &fixtureList = bodyData.at("fixtures").asValueVector();
        FixtureDef **nextFixtureDef = &(bodyDef->fixtures);
        for (auto &fixtureitem : fixtureList)
        {
            b2FixtureDef basicData;

            auto &fixturedata = fixtureitem.asValueMap();
            basicData.density         = fixturedata.at("density").asFloat();
            basicData.restitution      = fixturedata.at("restitution").asFloat();
            basicData.friction        = fixturedata.at("friction").asFloat();
            basicData.filter.categoryBits    = fixturedata.at("filter_categoryBits").asInt();
            basicData.filter.groupIndex           = fixturedata.at("filter_groupIndex").asInt();
            basicData.filter.maskBits   = fixturedata.at("filter_maskBits").asInt();
            basicData.isSensor             = fixturedata.at("isSensor").asBool();
            
            std::string fixtureType = fixturedata.at("fixture_type").asString();
            if (fixtureType == "POLYGON")
            {
                const ValueVector &polygonsArray = fixturedata.at("polygons").asValueVector();
                for (auto &polygonitem : polygonsArray)
                {
                    FixtureDef *fix = new FixtureDef();
                    fix->fixture = basicData; // copy basic data
                    
                    b2PolygonShape *polyshape = new b2PolygonShape();
                    int vindex = 0;
                    
                    auto &polygonArray = polygonitem.asValueVector();
                    for (auto &pointString : polygonArray)
                    {
                        auto offset = PointFromString(pointString.asString());
                        vertices[vindex].x = offset.x / ptmRatio;
                        vertices[vindex].y = offset.y / ptmRatio;
                        vindex++;
                    }
                    
                    polyshape->Set(vertices, vindex);
                    fix->fixture.shape = polyshape;
                    
                    // create a list
                    *nextFixtureDef = fix;
                    nextFixtureDef = &(fix->next);
                }

            }
            else if (fixtureType == "CIRCLE")
            {
                FixtureDef *fix = new FixtureDef();
                fix->fixture = basicData; // copy basic data
                
                const ValueMap &circleData = fixturedata.at("circle").asValueMap();
                
                b2CircleShape *circleShape = new b2CircleShape();
                
                circleShape->m_radius = circleData.at("radius").asFloat() / ptmRatio;
                Point p = PointFromString(circleData.at("position").asString());
                circleShape->m_p = b2Vec2(p.x / ptmRatio, p.y / ptmRatio);
                fix->fixture.shape = circleShape;
                
                // create a list
                *nextFixtureDef = fix;
                nextFixtureDef = &(fix->next);
                
            } else {
                CCAssert(0, "Unknown fixtureType");
            }
            
            // add the body element to the hash
            shapeObjects[bodyName] = bodyDef;
        }
        
    }
    
    return true;
}