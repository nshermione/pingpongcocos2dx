//
//  Physics.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/12/16.
//
//

#include "Physics.h"

START_GAME_NS

static Physics2DWorld *_world2D = NULL;

Physics2DWorld* Physics::createWorld2D(Physics2DType type) {
    switch (type) {
        case PhysicsCocos2DType:
            _world2D = new PhysicsCocos2DWorld();
            break;
        case PhysicsBox2DType:
            _world2D = new PhysicsBox2DWorld();
            break;
    }
    
    return _world2D;
}

Physics2DWorld* Physics::getWorld2D() {
    return _world2D;
};

END_GAME_NS