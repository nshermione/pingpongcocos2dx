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
    Chump();
    ~Chump();
    void init(cocos2d::Sprite *sprite,
              const std::string& name,
              cocos2d::Sprite *topEdge,
              cocos2d::Sprite *bottomEdge,
              bool flipped,
              bool isPlayed);
    void registerTouchEvents();
    void registerAI();
    
protected:
    Physics2DBody* physicsBody;
    cocos2d::Sprite* _topEdge;
    cocos2d::Sprite* _botEdge;
    Physics2DBody* _ballBody;
};


#endif /* Chump_h */
