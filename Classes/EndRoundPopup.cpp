//
//  EndRoundPopup.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#include "EndRoundPopup.h"

int step = 2;
float animationTime = 2.0f;

bool EndRoundPopup::init(std::string csbFile) {
    BaseScene::init(csbFile);
    
    return true;
}


int curGold = 0;
int curStar = 0;


void EndRoundPopup::start(int gold, int star) {
    auto goldLabel = (cocos2d::ui::Text *) _rootNode->getChildByName("moneyPlus");
    auto starLabel = (cocos2d::ui::Text *) _rootNode->getChildByName("starPlus");
    
    auto goldInterval = animationTime * step / gold;
    auto starInterval = animationTime * step / star;
    
    curGold = 0;
    curStar = 0;
    
    auto goldSchedule = [this, gold, goldLabel] (float dt) {
        curGold += step;
        
        if (curGold >= gold) {
            curGold = gold;
            this->unschedule("goldUpdate");
        }
        std::string sign = curGold >= 0? "+" : "";
        goldLabel->setString(sign + std::to_string(curGold));
    };
    
    auto starSchedule = [this, star, starLabel] (float dt) {
        curStar += step;
        
        if (curStar >= star) {
            curStar = star;
            this->unschedule("starUpdate");
        }
        std::string sign = curStar >= 0? "+" : "";
        starLabel->setString(sign + std::to_string(curStar));
    };
    
    schedule(goldSchedule, goldInterval, "goldUpdate");
    schedule(starSchedule, starInterval, "starUpdate");
    
    
    auto closePopup = [this] (float dt) {
        this->close();
    };
    
    scheduleOnce(closePopup, 4.0f, "closePopup");
}