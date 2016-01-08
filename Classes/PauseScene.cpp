#include "PauseScene.h"
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
        return false;
    }
    
    // Init scene here
    
    // End init scene
    return true;
}

