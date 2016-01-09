#include "EmptyScene.h"
#include "CSBHelper.h"

#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocos2d::ui;


Scene* Empty::createScene()
{
    auto scene = Scene::create();
    auto layer = Empty::create();
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool Empty::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    auto rootNode = CSBHelper::createNode("EmptyScene.csb");
    this->addChild(rootNode);
    this->bindButtons(rootNode);
    // End init scene
    return true;
}


void Empty::bindButtons(Node* rootNode) {
//    auto resumeButton = (Button *) rootNode->getChildByName("resumeButton");
//    
//    quitButton->addClickEventListener(CC_CALLBACK_0(Pause::quitGame, this));
}

