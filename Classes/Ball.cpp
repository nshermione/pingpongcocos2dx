//
//  Ball.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Ball.h"


void Ball::init(cocos2d::Sprite *sprite) {
    auto size = sprite->getContentSize();
    auto physicsBody = PhysicsBody::createCircle(size.width/2,
                                          PhysicsMaterial(0.1f, 1.0f, 0.0f));
    
    //set the body isn't affected by the physics world's gravitational force
    physicsBody->setGravityEnable(false);
    
    //set initial velocity of physicsBody
    physicsBody->setVelocity(Vec2(cocos2d::random(-100,100),
                                  cocos2d::random(-100,100)));
    sprite->setPhysicsBody(physicsBody);
}