//
//  Block.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Block.h"

USING_NS_CC;


void Block::init(cocos2d::Sprite *sprite) {
    auto size = sprite->getContentSize();
    log("Block size %f %f", size.width, size.height);
    auto physicsBody = PhysicsBody::createBox(size,
                                              PhysicsMaterial(0.1f, 1.0f, 1.0f));
    
    physicsBody->setDynamic(false);
    
    sprite->setPhysicsBody(physicsBody);
}