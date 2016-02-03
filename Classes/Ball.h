//
//  Ball.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef Ball_h
#define Ball_h

#include "GameObject.h"
#include "GameMacro.h"


USING_NS_GAME;

class Ball: public GameObject {
public:
    bool init(cocos2d::Sprite* sprite);
    static std::string NAME;
    
protected:
    
    void reset();
    void initParticle();
    void initShader();
    void initPhysics();
    
    void controlVelocity(float dt);
    void setVelocity(float vel);
    void setTrail(cocos2d::ParticleSystemQuad* trail);
    
    cocos2d::ParticleSystemQuad* trail1;
    cocos2d::ParticleSystemQuad* trail2;
    
    cocos2d::ParticleSystemQuad* currentTrail;
    float speedVariant;
    float speedByTime;
    float totalSpeed;
    float totalTime;
};

#endif /* Ball_h */
