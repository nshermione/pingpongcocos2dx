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

void Goal::init(cocos2d::Sprite *sprite, const std::string& name) {
    setSprite(sprite);
    setName(name);
    
    auto world = Physics::getWorld2D();
    auto physicsBody = world->addBodyBox(sprite,
                                         name,
                                         sprite->getContentSize(),
                                         PhysicsMaterial(0.1f, 1.0f, 1.0f));
    
    physicsBody->setDynamic(false);
    physicsBody->setCollisionBitmask(0x0001);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    
    // collision check
    auto listener = new Physics2DContactListener(physicsBody);
    listener->onContactBegin = CC_CALLBACK_1(Goal::onContactBegin, this);
    world->registerContactListener(listener);
}

bool Goal::onContactBegin(std::shared_ptr<Physics2DContact> contact) {
    if (contact->getTargetBody() != nullptr) {
        auto ball = contact->getOtherBody();
        auto ballSprite = ball->getSprite();
        if (ballSprite->getName() != Ball::NAME) {
            return false;
        }
        
        auto parentSprite = ballSprite->getParent();
        auto position = ballSprite->getPosition();
        auto disappear = ParticleSystemQuad::create("disappear.plist");
        parentSprite->addChild(disappear);
        disappear->setPosition(position);
        
        Physics::getWorld2D()->removeBody(ball);
        
        // play sound yay
        auto audio = SimpleAudioEngine::getInstance();
        audio->playEffect("yay.wav");
        
        return true;
    }
    return false;
}