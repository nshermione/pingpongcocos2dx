//
//  Table.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Table.h"
#include "Physics.h"

USING_NS_CC;

void Table::init(Sprite* sprite) {
    setSprite(sprite);
    auto world = Physics::getWorld2D();
    auto body = world->addBody(sprite, "table");
    body->setDensity(false);
}