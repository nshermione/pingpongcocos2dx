//
//  PhysicsShapeCache.h
//
//  Shape cache for Cocos2d-x (v3.x) with built-in physics classes.
//
//  Loads physics sprites created with https://www.codeandweb.com/physicseditor
//
//  Copyright (c) 2015 CodeAndWeb GmbH. All rights reserved.
//  https://www.codeandweb.com
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

#ifndef __PhysicsShapeCache_h__
#define __PhysicsShapeCache_h__
#include "cocos2d.h"


class BodyDef;
class FixtureData;


class PhysicsShapeCache
{
public:
    static PhysicsShapeCache *getInstance();
    static void destroyInstance();
    
    bool addShapesWithFile(const std::string &plist);
    bool addShapesWithFile(const std::string &plist, float scaleFactor);
    bool removeShapesWithFile(const std::string &plist);
    bool removeAllShapes();
    
    cocos2d::PhysicsBody *createBodyWithName(const std::string &name);
    bool setBodyOnSprite(const std::string &name, cocos2d::Sprite *sprite);
    
private:
    PhysicsShapeCache();
    ~PhysicsShapeCache();
    bool safeDeleteBodyDef(BodyDef *bodyDef);
    BodyDef *getBodyDef(const std::string &name);
    void setBodyProperties(cocos2d::PhysicsBody *body, BodyDef *bd);
    void setShapeProperties(cocos2d::PhysicsShape *shape, FixtureData *fd);
    
    std::map<std::string, BodyDef*> bodyDefs;
};


typedef enum
{
    FIXTURE_POLYGON,
    FIXTURE_CIRCLE
} FixtureType;


class Polygon
{
public:
    cocos2d::Point* vertices;
    int numVertices;
    
};


class FixtureData
{
public:
    FixtureType fixtureType;
    
    float density;
    float restitution;
    float friction;
    
    int tag;
    int group;
    int categoryMask;
    int collisionMask;
    int contactTestMask;
    
    // for circles
    cocos2d::Point center;
    float radius;
    
    // for polygons / polyline
    std::vector<Polygon *> polygons;
    
};


class BodyDef
{
public:
    cocos2d::Point anchorPoint;
    std::vector<FixtureData *> fixtures;
    
    bool isDynamic;
    bool affectedByGravity;
    bool allowsRotation;
    
    float linearDamping;
    float angularDamping;
    float velocityLimit;
    float angularVelocityLimit;
    
};


#endif // __PhysicsShapeCache_h