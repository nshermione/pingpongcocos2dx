#include "BaseScene.h"
#include "CSBHelper.h"


using namespace cocos2d::ui;


// on "init" you need to initialize your instance
bool BaseScene::init(std::string csbFile)
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    // Init scene here
    this->_rootNode = CSBHelper::createNode(csbFile);
    this->addChild(_rootNode);
    // End init scene
    return true;
}

void BaseScene::bindButton(std::string buttonName, const ui::Widget::ccWidgetClickCallback &callback) {
    auto button = (Button *) _rootNode->getChildByName(buttonName);
    button->addClickEventListener(callback);
}

