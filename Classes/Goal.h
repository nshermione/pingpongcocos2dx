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
    void init(Sprite *sprite);
    void intersect(Ball ball, std::function<void()> callBack);
    
protected:
    bool isFocus = false;
};


#endif /* Goal_h */
