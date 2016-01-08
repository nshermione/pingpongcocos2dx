#include "SplashScene.h"
#include "MainMenuScene.h"
#include "CSBHelper.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace cocos2d::ui;

Scene* Splash::createScene()
{
    auto scene = Scene::create();
    auto layer = Splash::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

LoadingBar* loadingBar;

// on "init" you need to initialize your instance
bool Splash::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSBHelper::createNode("SplashScene.csb");
    this->addChild(rootNode);
    
    loadingBar = (LoadingBar *)rootNode->getChildByName("loadingBar");
    this->schedule(schedule_selector(Splash::updateProgress), 0.01f);

    return true;
}

void Splash::nextScene(float dt) {
    Director::getInstance()->replaceScene(MainMenu::createScene());
}

float counter = 0;
void Splash::updateProgress(float dt) {
    counter++;
    if (counter > 100)
    {
        unschedule(schedule_selector(Splash::updateProgress));
        this->scheduleOnce(schedule_selector(Splash::nextScene), 0.05f);
    }
    loadingBar->setPercent(counter);
}



