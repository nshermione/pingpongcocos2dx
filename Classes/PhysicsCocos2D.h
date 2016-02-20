//
//  Physics2DCocos.hpp
//  pingpong
//
//  Created by Thinh Tran on 2/11/16.
//
//

#ifndef PhysicsCocos2D_h
#define PhysicsCocos2D_h

#include "cocos2d.h"
#include "GameMacro.h"
#include "PhysicsShapeCache.h"
#include "Physics2D.h"

START_GAME_NS

class PhysicsCocos2DBody : public Physics2DBody {
public:
    PhysicsCocos2DBody();
    ~PhysicsCocos2DBody();
    
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
    bool isDeleted();
    
    void setBody(cocos2d::PhysicsBody *body) {
        _body = body;
    }
private:
    cocos2d::PhysicsBody *_body;
    std::string _name;
};

class PhysicsCocos2DWorld : public Physics2DWorld {
public:
    PhysicsCocos2DWorld();
    ~PhysicsCocos2DWorld();
    void init(cocos2d::Scene *scene, float gravityX, float gravityY);
    std::shared_ptr<Physics2DBody> addBody(cocos2d::Sprite* sprite, const std::string &bodyName, const std::string &bodyPrototype);
    std::shared_ptr<Physics2DBody> addBodyBox(cocos2d::Sprite* sprite,
                                      const std::string &bodyName,
                                      const cocos2d::Size& size,
                                      cocos2d::PhysicsMaterial material);
    std::shared_ptr<Physics2DBody> addBodyCircle(cocos2d::Sprite* sprite,
                                         const std::string &bodyName, 
                                         float radius,
                                         cocos2d::PhysicsMaterial material);
    std::shared_ptr<Physics2DBody> findBody(const std::string& name);
    void removeBody(Physics2DBody *body);
    void loadBodies(const std::string &plist);
    void registerContactListener(Physics2DContactListener* listener);
    void drawDebug();
    
private:
    cocos2d::PhysicsWorld *_world;
    std::vector<std::shared_ptr<Physics2DBody>> _bodies;
    std::unordered_map<std::string, std::shared_ptr<Physics2DBody>> _bodyMapByName;
};

END_GAME_NS

#endif /* PhysicsCocos2D_h */
