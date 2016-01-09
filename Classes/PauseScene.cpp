#include "PauseScene.h"
#include "MainMenuScene.h"
#include "CSBHelper.h"

#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;


Scene* Pause::createScene()
{
    auto scene = Scene::create();
    auto layer = Pause::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Pause::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    auto rootNode = CSBHelper::createNode("PauseScene.csb");
    this->addChild(rootNode);
    
    this->bindButtons(rootNode);
    // End init scene
    return true;
}

void Pause::bindButtons(Node* rootNode) {
    auto resumeButton = (Button *) rootNode->getChildByName("resumeButton");
    auto menuButton = (Button *) rootNode->getChildByName("menuButton");
    auto quitButton = (Button *) rootNode->getChildByName("quitButton");
    
    resumeButton->addClickEventListener(CC_CALLBACK_0(Pause::resumeGame, this));
    menuButton->addClickEventListener(CC_CALLBACK_0(Pause::goToMainMenu, this));
    quitButton->addClickEventListener(CC_CALLBACK_0(Pause::quitGame, this));
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

