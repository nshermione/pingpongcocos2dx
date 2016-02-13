//
//  Block.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Block.h"
#include "Physics.h"

USING_NS_CC;


void Block::init(cocos2d::Sprite *sprite) {
    auto world = Physics::getWorld2D();
    auto physicsBody = world->addBody(sprite, "block");
    physicsBody->setDynamic(false);
}