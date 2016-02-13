//
//  Physics2D.h
//  pingpong
//
//  Created by Thinh Tran on 2/11/16.
//
//

#ifndef Physics2D_h
#define Physics2D_h

#include "cocos2d.h"

class Physics2DBody {
public:
    virtual void setDensity(float density) = 0;
    virtual void setFriction(float friction) = 0;
    virtual void setRestitution(float restitution) = 0;
    virtual void setMaterial(float density, float friction, float restitution) = 0;
    virtual void setGroup(int groupId) = 0;
    virtual void setCategoryBitmask(int bitmask) = 0;
    virtual void setCollisionBitmask(int bitmask) = 0;
    virtual void setContactTestBitmask(int bitmask) = 0;
    virtual void setDynamic(bool isDynamic) = 0;
    virtual void setGravity(bool inGravity) = 0;
    virtual void setVelocity(const cocos2d::Vec2& vel) = 0;
    virtual cocos2d::Vec2 getVelocity() = 0;
    
    void setSprite(cocos2d::Sprite *sprite) { _bodySprite = sprite; }
    cocos2d::Sprite* getSprite() { return _bodySprite; };
    
protected:
    cocos2d::Sprite *_bodySprite;
};

class Physics2DContact {
    virtual Physics2DBody getBodyA() = 0;
    virtual Physics2DBody getBodyB() = 0;
    virtual cocos2d::Sprite getSpriteA() = 0;
    virtual cocos2d::Sprite getSpriteB() = 0;
};

class Physics2DContactListener {
    std::function<Physics2DContact> onContactBegin();
    std::function<Physics2DContact> onContactEnd();
    std::function<Physics2DContact> onContactPreSolve();
    std::function<Physics2DContact> onContactPostSolve();
};

class Physics2DWorld {
public:
    virtual void init(cocos2d::Scene *scene, float gravityX, float gravityY) {
        _scene = scene;
    }
    virtual Physics2DBody* addBody(cocos2d::Sprite* sprite, const std::string &bodyName) = 0;
    virtual Physics2DBody* addBodyBox(cocos2d::Sprite* sprite,
                                             const cocos2d::Size& size,
                                             cocos2d::PhysicsMaterial material) = 0;
    virtual Physics2DBody* addBodyCircle(cocos2d::Sprite* sprite,
                                             float radius,
                                             cocos2d::PhysicsMaterial material) = 0;
    virtual void loadBodies(const std::string &plist) = 0;
    virtual void registerContactListener(Physics2DContactListener listener) = 0;
    virtual void drawDebug() = 0;
    
protected:
    cocos2d::Scene *_scene;
};

#endif /* Physics2D_h */
