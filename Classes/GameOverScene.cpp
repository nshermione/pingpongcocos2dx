#include "GameOverScene.h"
#include "PlayScene.h"
#include "MainMenuScene.h"

USING_NS_CC;
USING_NS_CC_UI;

// on "init" you need to initialize your instance
bool GameOver::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("retryButton", CC_CALLBACK_0(GameOver::retryGame, this));
    bindButton("menuButton", CC_CALLBACK_0(GameOver::goToMainMenu, this));
    
    // End init scene
    return true;
}

void GameOver::retryGame() {
    auto playScene = Play::createScene();
    Director::getInstance()->replaceScene(playScene);
}

void GameOver::goToMainMenu() {
    auto mainMenuScene = MainMenu::createScene();
    Director::getInstance()->replaceScene(mainMenuScene);
}

