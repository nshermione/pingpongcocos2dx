#include "MainMenuScene.h"
#include "SettingsScene.h"
#include "PlayScene.h"
#include "CSBHelper.h"

#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;

Scene* MainMenu::createScene()
{
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenu::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    auto rootNode = CSBHelper::createNode("MainMenuScene.csb");
    this->addChild(rootNode);
    
    bindButtons(rootNode);
    
    // End init scene
    return true;
}

void MainMenu::bindButtons(Node* rootNode) {
    auto playButton = (Button *) rootNode->getChildByName("playButton");
    auto settingButton = (Button *) rootNode->getChildByName("settingButton");
    auto quitButton = (Button *) rootNode->getChildByName("quitButton");
    
    playButton->addClickEventListener(CC_CALLBACK_0(MainMenu::playGame, this));
    settingButton->addClickEventListener(CC_CALLBACK_0(MainMenu::settings, this));
    quitButton->addClickEventListener(CC_CALLBACK_0(MainMenu::quitGame, this));
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

