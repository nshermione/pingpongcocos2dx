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

START_GAME_NS

// PATCH - sprite from csb file use content scale factor
void fixSpriteContentScale(Node* parentNode) {
    auto childrenNodes = parentNode->getChildren();
    for (auto it = childrenNodes.begin(); it != childrenNodes.end(); it++) {
        auto childNode = *it;
        if (dynamic_cast<Sprite*>(childNode) != NULL) {
            auto sprite = dynamic_cast<Sprite*>(childNode);
            sprite->setScale(sprite->getScaleX() * Director::getInstance()->getContentScaleFactor(),
                             sprite->getScaleY() * Director::getInstance()->getContentScaleFactor());
            
        }
        fixSpriteContentScale(childNode);
        
    }
}

Node* CSBHelper::createNode(const std::string& csbFile) {
    auto deviceSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();

    auto _rootNode = CSLoader::createNode(csbFile);
    auto sceneSize = _rootNode->getContentSize();
    
    
    _rootNode->setScale( (deviceSize.width/sceneSize.width),
                        (deviceSize.height/sceneSize.height));

    fixSpriteContentScale(_rootNode);
    
    _rootNode->setPosition(origin);
    return _rootNode;
}

END_GAME_NS
