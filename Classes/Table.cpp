//
//  Table.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Table.h"

USING_NS_CC;

void Table::init(std::vector<Sprite*> &sprites) {
    for (auto it = sprites.begin(); it != sprites.end(); ++it) {
        auto sprite = *it;
        auto size = sprite->getContentSize();
        cocos2d::log("Table size %f %f", size.width, size.height);
        auto physicsBody = PhysicsBody::createBox(size,
                                            PhysicsMaterial(0.1f, 1.0f, 1.0f));
        
        physicsBody->setDynamic(false);
        
        sprite->setPhysicsBody(physicsBody);
    }
    
}