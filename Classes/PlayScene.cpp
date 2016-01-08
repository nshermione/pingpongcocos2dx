#include "PlayScene.h"
#include "PauseScene.h"
#include "CSBHelper.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;

Scene* Play::createScene()
{
    auto scene = Scene::create();
    auto layer = Play::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Play::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    auto rootNode = CSBHelper::createNode("PlayScene.csb");
    this->addChild(rootNode);
    
    bindButtons(rootNode);
    
    // End init scene
    return true;
}

void Play::bindButtons(Node* rootNode) {
    auto playButton = (Button *) rootNode->getChildByName("menuButton");
    
    playButton->addClickEventListener(CC_CALLBACK_0(Play::goToPauseScene, this));
}

void Play::goToPauseScene() {
    auto pauseScene = Pause::createScene();
    Director::getInstance()->pushScene(pauseScene);
}

