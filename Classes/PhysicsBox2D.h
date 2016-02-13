//
//  PhysicsBox2D.h
//  pingpong
//
//  Created by Thinh Tran on 2/11/16.
//
//

#ifndef PhysicsBox2D_h
#define PhysicsBox2D_h

#include "cocos2d.h"
#include "box2d/Box2D.h"

#include "GameMacro.h"
#include "GB2ShapeCache-x.h"
#include "Physics2D.h"

START_GAME_NS

class PhysicsBox2DBody : public Physics2DBody {
public:
    PhysicsBox2DBody();
    ~PhysicsBox2DBody();
    
    void setDensity(float density);
    void setFriction(float friction);
    void setRestitution(float restitution);
    void setMaterial(float density, float friction, float restitution);
    void setGroup(int groupId);
    void setCategoryBitmask(int bitmask);
    void setCollisionBitmask(int bitmask);
    void setContactTestBitmask(int bitmask);
    void setDynamic(bool isDynamic);
    void setGravity(bool inGravity);
    void setVelocity(const cocos2d::Vec2& vel);
    cocos2d::Vec2 getVelocity();
    
    void setBody(b2Body *body) {
        _body = body;
    }
    
private:
    b2Body *_body;
};



class PhysicsBox2DWorld : public Physics2DWorld {
public:
    void init(cocos2d::Scene *scene, float gravityX, float gravityY);
    Physics2DBody* addBody(cocos2d::Sprite* sprite, const std::string &bodyName);
    Physics2DBody* addBodyBox(cocos2d::Sprite* sprite,
                                      const cocos2d::Size& size,
                                      cocos2d::PhysicsMaterial material);
    Physics2DBody* addBodyCircle(cocos2d::Sprite* sprite,
                                         float radius,
                                         cocos2d::PhysicsMaterial material);
    void loadBodies(const std::string &plist);
    void registerContactListener(Physics2DContactListener listener);
    void drawDebug();
    
private:
    b2World *_world;
};

END_GAME_NS

#endif /* PhysicsBox2D_h */
