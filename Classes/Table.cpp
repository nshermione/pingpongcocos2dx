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

void Table::init(Sprite* sprite, const std::string& name) {
    setSprite(sprite);
    setName(name);
    auto world = Physics::getWorld2D();
    auto body = world->addBody(sprite, name, "table");
    body->setDensity(false);
}