//
//  Chump.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Chump.h"
#include "Physics.h"

USING_NS_CC;


void Chump::init(cocos2d::Sprite *sprite, bool flipped) {
    setSprite(sprite);
    std::string bodyName = flipped? "chump3_flip" : "chump3";

    auto world = Physics::getWorld2D();
    world->addBody(sprite, bodyName);
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