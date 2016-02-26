//
//  Goal.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Goal.h"
#include "Physics.h"
#include "EndRoundPopup.h"
#include "Match.h"

USING_NS_CC;
using namespace CocosDenshion;

void Goal::init(cocos2d::Sprite *sprite, const std::string& name) {
    GameObject::init(name);
    setSprite(sprite);
    setName(name);
    
    auto world = Physics::getWorld2D();
    _physicsBody = world->addBodyBox(sprite,
                                         name,
                                         sprite->getContentSize(),
                                         PhysicsMaterial(0.1f, 1.0f, 1.0f));
    
    _physicsBody->setDynamic(false);
    _physicsBody->setCollisionBitmask(0x0001);
    _physicsBody->setContactTestBitmask(0xFFFFFFFF);
    
    // collision check
    auto listener = new Physics2DContactListener(_physicsBody.get());
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
        
        // effect
        auto parentSprite = ballSprite->getParent();
        auto position = ballSprite->getPosition();
        auto disappear = ParticleSystemQuad::create("disappear.plist");
        parentSprite->addChild(disappear);
        disappear->setPosition(position);
        
        // remove ball
        Physics::getWorld2D()->removeBody(ball);
        ballSprite->removeFromParent();
        
        // end round
        auto endRoundCallback = [this] (float dt) {
            auto match = Match::getInstance();
            match->endRound(this->getName());
        };
        
        getSprite()->scheduleOnce(endRoundCallback, 2, "openEndRoundPopup");
        
        return true;
    }
    return false;
}