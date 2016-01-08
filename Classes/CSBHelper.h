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

USING_NS_CC;

class CSBHelper {
public:
    static Node* createNode(const std::string& csbFile);
};

#endif /* CSBHelper_hpp */
