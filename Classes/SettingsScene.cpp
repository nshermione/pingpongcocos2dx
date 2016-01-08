#include "SettingsScene.h"
#include "CSBHelper.h"

USING_NS_CC;


Scene* Settings::createScene()
{
    auto scene = Scene::create();
    auto layer = Settings::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Settings::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    
    // End init scene
    return true;
}

