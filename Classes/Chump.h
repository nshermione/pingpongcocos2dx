//
//  Chump.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef Chump_h
#define Chump_h

#include "GameObject.h"
#include "GameMacro.h"
#include "Physics2D.h"

USING_NS_GAME;

class Chump: public GameObject {
public:
    void init(cocos2d::Sprite *sprite, bool flipped);
    void registerTouchEvents();
    
protected:
    Physics2DBody* physicsBody;
    
};


#endif /* Chump_h */
