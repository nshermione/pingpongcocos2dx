#include "MainMenuScene.h"
#include "SettingsScene.h"
#include "PlayScene.h"
#include "StoreScene.h"

USING_NS_CC;
USING_NS_CC_UI;

// on "init" you need to initialize your instance
bool MainMenu::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("playButton", CC_CALLBACK_0(MainMenu::playGame, this));
    bindButton("storeButton", CC_CALLBACK_0(MainMenu::goToStore, this));
    // Settings scene is not needed now
    //bindButton("settingButton", CC_CALLBACK_0(MainMenu::settings, this));
    bindButton("quitButton", CC_CALLBACK_0(MainMenu::quitGame, this));
    
    // End init scene
    return true;
}

void MainMenu::goToStore() {
    auto storeScene = Store::createScene();
    Director::getInstance()->pushScene(storeScene);
}

void MainMenu::quitGame() {
    Director::getInstance()->end();
    exit(0);
}

void MainMenu::settings() {
    auto settingsScene = Settings::createScene();
    Director::getInstance()->pushScene(settingsScene);
}

void MainMenu::playGame() {
    auto playScene = Play::createScene();
    Director::getInstance()->replaceScene(playScene);
}

