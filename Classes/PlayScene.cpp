#include "PlayScene.h"
#include "PauseScene.h"


// on "init" you need to initialize your instance
bool Play::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("menuButton", CC_CALLBACK_0(Play::goToPauseScene, this));
    
    return true;
}

void Play::goToPauseScene() {
    auto pauseScene = Pause::createScene();
    Director::getInstance()->pushScene(pauseScene);
}

