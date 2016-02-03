//
//  Goal.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Goal.h"

USING_NS_CC;

void Goal::init(cocos2d::Sprite *sprite) {
    setSprite(sprite);
    auto size = sprite->getContentSize();
    log("Goal size %f %f", size.width, size.height);
    auto physicsBody = PhysicsBody::createBox(size,
                                           PhysicsMaterial(0.1f, 1.0f, 1.0f));
    
    physicsBody->setDynamic(false);
    physicsBody->setCollisionBitmask(0x0001);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    sprite->setPhysicsBody(physicsBody);
    
    // collision check
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Goal::onContactBegin, this);
    sprite->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, sprite);
}

bool Goal::onContactBegin(cocos2d::PhysicsContact& contact) {
    auto bodyA = contact.getShapeA()->getBody();
    auto bodyB = contact.getShapeB()->getBody();
    if (bodyA && bodyB) {
        
    }
    return false;
}