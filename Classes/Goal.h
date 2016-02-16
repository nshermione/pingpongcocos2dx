//
//  Goal.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef Goal_h
#define Goal_h

#include "GameObject.h"
#include "GameMacro.h"
#include "Ball.h"

USING_NS_GAME;

class Goal: public GameObject {
public:
    void init(cocos2d::Sprite *sprite);
    bool onContactBegin(std::shared_ptr<Physics2DContact> contact);
    
protected:
};


#endif /* Goal_h */
