#include "PlayScene.h"
#include "PauseScene.h"
#include "Player.h"

// on "init" you need to initialize your instance
bool Play::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("menuButton", CC_CALLBACK_0(Play::goToPauseScene, this));
    
    auto playerLabel = (ui::Text *) _rootNode->getChildByName("playerName");
    auto playerName = Player::getInstance()->name;
    playerLabel->setString(playerName);
    return true;
}

void Play::goToPauseScene() {
    auto pauseScene = Pause::createScene();
    Director::getInstance()->pushScene(pauseScene);
}

