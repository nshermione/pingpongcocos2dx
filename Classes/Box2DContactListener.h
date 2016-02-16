//
//  Box2DContactListener.hpp
//  pingpong
//
//  Created by Thinh Tran on 2/15/16.
//
//

#ifndef Box2DContactListener_h
#define Box2DContactListener_h

#include "box2d/Box2D.h"
#include "Physics2D.h"
#include "PhysicsBox2D.h"

START_GAME_NS

class Box2DContactListener : public b2ContactListener {
public:
    Box2DContactListener(PhysicsBox2DWorld* world) {
        _world = world;
    }
    ~Box2DContactListener() {}
    
    void addListener(Physics2DContactListener* listener) {
        _listeners.push_back(listener);
    }
    
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact) ;
    void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) ;
    void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
    
private:
    std::vector<Physics2DContactListener*> _listeners;
    PhysicsBox2DWorld* _world;
    std::shared_ptr<PhysicsBox2DContact> _pContact;
};

END_GAME_NS

#endif /* Box2DContactListener_h */
