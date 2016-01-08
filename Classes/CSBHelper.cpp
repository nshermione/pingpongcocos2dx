//
//  CSBHelper.cpp
//  hellococos2dx
//
//  Created by Thinh Tran on 1/6/16.
//
//

#include "CSBHelper.h"
#include "cocostudio/CocoStudio.h"

USING_NS_CC;


Node* CSBHelper::createNode(const std::string& csbFile) {
    auto deviceSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    auto rootNode = CSLoader::createNode(csbFile);
    auto sceneSize = rootNode->getBoundingBox().size;
    
    rootNode->setScale(deviceSize.width/sceneSize.width, deviceSize.height/sceneSize.height);
    rootNode->setPosition(origin);
    return rootNode;
}
