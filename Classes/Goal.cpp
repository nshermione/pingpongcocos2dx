//
//  Goal.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Goal.h"


void Goal::init(cocos2d::Sprite *sprite) {
    setSprite(sprite);
}

void Goal::intersect(Ball ball, std::function<void()> callBack) {
    auto ballSprite = ball.getSprite();
    auto ballBox = ballSprite->getBoundingBox();
    auto goalBox = this->getSprite()->getBoundingBox();
    auto isIntersect = ballBox.intersectsRect(goalBox);
    if (isIntersect && !isFocus) {
        isFocus = true;
        callBack();
    } else {
        isFocus = false;
    }
}