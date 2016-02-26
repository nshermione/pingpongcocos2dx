//
//  Portal.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Portal.h"

USING_NS_CC;


bool Portal::inPortal = false;

void Portal::init(cocos2d::Sprite *sprite,
                  const std::string& name,
                  cocos2d::Sprite *oppositeSprite,
                  cocos2d::Sprite *portalCollider) {
    GameObject::init(name);
    setSprite(sprite);
    setName(name);
    _oppositeSprite = oppositeSprite;
    _portalCollider = portalCollider;
    
    auto world = Physics::getWorld2D();
    _ballBody = world->findBody("ball");
    
    auto rotateAction = RotateBy::create(2, 360);
    
    sprite->runAction(
        RepeatForever::create(rotateAction)
    );
    
    
    sprite->schedule(CC_CALLBACK_1(Portal::ballCollisionCheck, this), 0.016, "ballCollisionCheck");
    
}

void Portal::ballCollisionCheck(float dt) {
    _ballSprite = (Sprite*) getSprite()->getParent()->getChildByName("ball");
    if (
        _ballSprite != nullptr &&
        !_ballBody->isDeleted() &&
        _portalCollider->getBoundingBox().intersectsRect(_ballSprite->getBoundingBox())) {
        
        auto teleportAction = Sequence::create(
                                               CallFunc::create(CC_CALLBACK_0(Portal::teleport, this)),
                                               DelayTime::create(0.25f),
                                               CallFunc::create(CC_CALLBACK_0(Portal::endTeleport, this)),
                                               nullptr
                                                );
        _ballSprite->runAction(teleportAction);
    }
}

void Portal::teleport() {
    if (!_ballBody->isDeleted() && !Portal::inPortal) {
        Portal::inPortal = true;
        auto world = Physics::getWorld2D();
        auto ballBody = world->findBody("ball");
        auto targetPosition = _oppositeSprite->getPosition();
        ballBody->setPosition(targetPosition);
    }
}

void Portal::endTeleport() {
    if (!_ballBody->isDeleted() && Portal::inPortal) {
        Portal::inPortal = false;
    }
}