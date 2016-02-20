#include "StoreScene.h"
#include "MainMenuScene.h"

USING_NS_CC;
USING_NS_CC_UI;

// on "init" you need to initialize your instance
bool Store::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("home", CC_CALLBACK_0(Store::backToHome, this));
    
    return true;
}

void Store::backToHome() {
    auto homeScene = MainMenu::createScene();
    Director::getInstance()->replaceScene(homeScene);
}

