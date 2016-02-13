//
//  Goal.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Goal.h"
#include "Physics.h"

USING_NS_CC;
using namespace CocosDenshion;

void Goal::init(cocos2d::Sprite *sprite) {
    setSprite(sprite);
    
    auto world = Physics::getWorld2D();
    auto physicsBody = world->addBodyBox(sprite,
                                         sprite->getContentSize(),
                                         PhysicsMaterial(0.1f, 1.0f, 1.0f));
    
    physicsBody->setDynamic(false);
    physicsBody->setCollisionBitmask(0x0001);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    
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
        
        // play sound yay
        auto audio = SimpleAudioEngine::getInstance();
        audio->playEffect("yay.wav");
    }
    return false;
}