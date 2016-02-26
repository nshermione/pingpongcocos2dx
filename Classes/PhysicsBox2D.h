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
    bool isDynamic();
    void setGravity(bool inGravity);
    void setVelocity(const cocos2d::Vec2& vel);
    cocos2d::Vec2 getVelocity();
    void setPosition(const cocos2d::Vec2& vel);
    void movePosition(const cocos2d::Vec2& vel);
    cocos2d::Vec2 getPosition();
    bool isSupportCCD();
    void enableCCD();
    const std::string& getName();
    void setName(const std::string& name);
    
    void setBody(b2Body *body) ;
    b2Body* getBody() ;
    void setDeleteFlag(bool isDeleted);
    bool isDeleted();
    
private:
    b2Body *_body;
    bool deleteFlag;
    std::string _name;
};



class PhysicsBox2DWorld : public Physics2DWorld {
public:
    PhysicsBox2DWorld();
    ~PhysicsBox2DWorld();
    void init(cocos2d::Scene *scene, float gravityX, float gravityY);
    std::shared_ptr<Physics2DBody> addBody(cocos2d::Sprite* sprite, const std::string &bodyName, const std::string &bodyPrototype);
    std::shared_ptr<Physics2DBody> addBodyBox(cocos2d::Sprite* sprite,
                                      const std::string &bodyName,
                                      const cocos2d::Size& size,
                                      cocos2d::PhysicsMaterial material);
    std::shared_ptr<Physics2DBody>addBodyCircle(cocos2d::Sprite* sprite,
                                         const std::string &bodyName, 
                                         float radius,
                                         cocos2d::PhysicsMaterial material);
    std::shared_ptr<Physics2DBody> findBody(const std::string& name);
    std::shared_ptr<Physics2DBody> findBody(b2Body *b2Body);
    void removeBody(Physics2DBody *body);
    void removeAllBodies();
    void loadBodies(const std::string &plist);
    void registerContactListener(Physics2DContactListener* listener);
    void drawDebug();
    void pause();
    void resume();
    
private:
    void update(float dt);
    b2World *_world;
    std::unordered_map<b2Body*, std::shared_ptr<PhysicsBox2DBody>> _bodyMap;
    std::unordered_map<std::string, std::shared_ptr<PhysicsBox2DBody>> _bodyMapByName;
    b2ContactListener *_contactListener;
    bool _paused;
};



class PhysicsBox2DContact : public Physics2DContact {
public:
    PhysicsBox2DContact(PhysicsBox2DWorld* world, b2Contact* contact, Physics2DBody* target=nullptr);
    ~PhysicsBox2DContact();
    Physics2DBody* getBodyA();
    Physics2DBody* getBodyB();
    cocos2d::Sprite* getSpriteA();
    cocos2d::Sprite* getSpriteB();
    Physics2DBody* getTargetBody();
    Physics2DBody* getOtherBody();
    void changeTarget(Physics2DBody* target);
    
private:
    Physics2DBody* bodyA;
    Physics2DBody* bodyB;
    Physics2DBody* targetBody;
    Physics2DBody* otherBody;
};

END_GAME_NS

#endif /* PhysicsBox2D_h */
