//
//  Block.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Block.h"


void Block::init(cocos2d::Sprite *sprite) {
    auto size = sprite->getContentSize();
    log("Block size %f %f", size.width, size.height);
    auto leftBody = PhysicsBody::createEdgeBox(size,
                                              PhysicsMaterial(0.1f, 1.0f, 1.0f));
    
    leftBody->setDynamic(false);
    
    sprite->setPhysicsBody(leftBody);
}