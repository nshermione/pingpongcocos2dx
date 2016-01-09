#include "GameOverScene.h"
#include "PlayScene.h"
#include "MainMenuScene.h"
#include "CSBHelper.h"

#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;


Scene* GameOver::createScene()
{
    auto scene = Scene::create();
    auto layer = GameOver::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    auto rootNode = CSBHelper::createNode("GameOverScene.csb");
    this->addChild(rootNode);
    this->bindButtons(rootNode);
    // End init scene
    return true;
}


void GameOver::bindButtons(Node* rootNode) {
    auto resumeButton = (Button *) rootNode->getChildByName("retryButton");
    auto menuButton = (Button *) rootNode->getChildByName("menuButton");
    
    resumeButton->addClickEventListener(CC_CALLBACK_0(GameOver::retryGame, this));
    menuButton->addClickEventListener(CC_CALLBACK_0(GameOver::goToMainMenu, this));
}

void GameOver::retryGame() {
    auto playScene = Play::createScene();
    Director::getInstance()->replaceScene(playScene);
}

void GameOver::goToMainMenu() {
    auto mainMenuScene = MainMenu::createScene();
    Director::getInstance()->replaceScene(mainMenuScene);
}

