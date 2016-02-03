//
//  CSBHelper.hpp
//  hellococos2dx
//
//  Created by Thinh Tran on 1/6/16.
//
//

#ifndef CSBHelper_h
#define CSBHelper_h

#include "cocos2d.h"

#include "GameMacro.h"

START_GAME_NS

class CSBHelper {
public:
    static cocos2d::Node* createNode(const std::string& csbFile);
};

END_GAME_NS

#endif /* CSBHelper_hpp */
