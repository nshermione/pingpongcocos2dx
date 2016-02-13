//
//  Physics.h
//  pingpong
//
//  Created by Thinh Tran on 2/12/16.
//
//

#ifndef Physics_h
#define Physics_h

#include "Physics2D.h"
#include "PhysicsBox2D.h"
#include "PhysicsCocos2D.h"

START_GAME_NS

enum Physics2DType {
    PhysicsCocos2DType,
    PhysicsBox2DType
};

class Physics {
public:
    static Physics2DWorld* createWorld2D(Physics2DType type);
    static Physics2DWorld* getWorld2D();
};

END_GAME_NS

#endif /* Physics_h */
