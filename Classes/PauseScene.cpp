#include "PauseScene.h"
#include "MainMenuScene.h"

// on "init" you need to initialize your instance
bool Pause::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("resumeButton", CC_CALLBACK_0(Pause::resumeGame, this));
    bindButton("menuButton", CC_CALLBACK_0(Pause::goToMainMenu, this));
    bindButton("quitButton", CC_CALLBACK_0(Pause::quitGame, this));

    // End init scene
    return true;
}

void Pause::resumeGame() {
    Director::getInstance()->popScene();
}

void Pause::goToMainMenu() {
    auto mainMenu = MainMenu::createScene();
    Director::getInstance()->replaceScene(mainMenu);
}

void Pause::quitGame() {
    Director::getInstance()->end();
    exit(0);
}

