//
//  Portal.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef Portal_h
#define Portal_h

#include "GameObject.h"
#include "GameMacro.h"
#include "Physics.h"

USING_NS_GAME;

class Portal: public GameObject {
public:
    void init(cocos2d::Sprite *sprite,
              const std::string& name,
              cocos2d::Sprite *oppositeSprite,
              cocos2d::Sprite *portalCollider);
    
protected:
    void ballCollisionCheck(float dt);
    void teleport();
    void endTeleport();
    
    cocos2d::Sprite* _oppositeSprite;
    cocos2d::Sprite* _ballSprite;
    cocos2d::Sprite* _portalCollider;
    std::shared_ptr<Physics2DBody> _ballBody;
    
    static bool inPortal;
};


#endif /* Portal_h */
