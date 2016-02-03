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
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA && nodeB) {
        auto ball = nodeA->getName()==Ball::NAME? nodeA : nodeB;
        auto parent = ball->getParent();
        auto position = ball->getPosition();
        auto disappear = ParticleSystemQuad::create("disappear.plist");
        parent->addChild(disappear);
        disappear->setPosition(position);
        
        ball->removeFromParentAndCleanup(true);
    }
    return false;
}