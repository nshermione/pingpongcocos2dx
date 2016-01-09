#ifndef __BaseScene_SCENE_H__
#define __BaseScene_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

#include "GameMacro.h"

USING_NS_CC;

class BaseScene : public cocos2d::Layer
{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(BaseScene, "");
    
protected:
    Node* rootNode;
    
    virtual bool init(std::string csbFile);
    virtual void bindButton(std::string buttonName, const ui::Widget::ccWidgetClickCallback &callback);
};

#endif // __BaseScene_SCENE_H__
