//
//  Table.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Table.h"


void Table::setSprite(cocos2d::Sprite *sprite) {
    this->sprite = sprite;
}

Sprite* Table::getSprite() {
    return this->sprite;
}
