//
//  Chump.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Chump.h"
#include "PhysicsShapeCache.h"

USING_NS_CC;


void Chump::init(cocos2d::Sprite *sprite, bool flipped) {
    setSprite(sprite);
    PhysicsBody* physicsBody;
    if (flipped) {
        physicsBody = PhysicsShapeCache::getInstance()->createBodyWithName("chump3_flip");
    } else {
        physicsBody = PhysicsShapeCache::getInstance()->createBodyWithName("chump3");
    }
    sprite->setPhysicsBody(physicsBody);
}

void Chump::registerTouchEvents() {
    auto listener = EventListenerTouchOneByOne::create();
    auto sprite = getSprite();
    
    listener->onTouchBegan = [] (Touch* touch, Event* event) {
        return true;
    };
    
    listener->onTouchMoved = [] (Touch* touch, Event* event) {
        auto target = event->getCurrentTarget();
        auto dy = touch->getDelta().y * target->getScaleY();
        dy = dy + target->getPositionY();
        target->setPositionY(dy);
    };
    

    auto eventDispatcher = sprite->getEventDispatcher();
    
    eventDispatcher->addEventListenerWithSceneGraphPriority(listener, sprite);
}