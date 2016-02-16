//
//  Physics.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/12/16.
//
//

#include "Physics.h"

START_GAME_NS

static std::shared_ptr<Physics2DWorld> _world2D = nullptr;

Physics::Physics () {
    
}

Physics::~Physics() {

}

Physics2DWorld* Physics::createWorld2D(Physics2DType type) {
    switch (type) {
        case PhysicsCocos2DType:
            _world2D = std::make_shared<PhysicsCocos2DWorld>();
            break;
        case PhysicsBox2DType:
            _world2D = std::make_shared<PhysicsBox2DWorld>();
            break;
    }
    
    return _world2D.get();
}

Physics2DWorld* Physics::getWorld2D() {
    return _world2D.get();
};

END_GAME_NS