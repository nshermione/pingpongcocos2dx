//
//  Table.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Table.h"


void Table::init(cocos2d::Sprite *sprite) {
    auto size = sprite->getContentSize();
    log("Table size %f %f", size.width, size.height);
    auto leftBody = PhysicsBody::createEdgeBox(size,
                                              PhysicsMaterial(0.1f, 1.0f, 0.0f));
    
    leftBody->setDynamic(false);
    
    sprite->setPhysicsBody(leftBody);
}