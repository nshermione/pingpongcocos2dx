#ifndef __MainMenu_SCENE_H__
#define __MainMenu_SCENE_H__

#include "cocos2d.h"
#include "ui/CocosGUI.h"

using namespace cocos2d::ui;

class MainMenu : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void quitGame();
    void playGame();
    void settings();
    
    // implement the "static create()" method manually
    CREATE_FUNC(MainMenu);
    
private:
    void bindButtons(Node* rootNode);
};

#endif // __MainMenu_SCENE_H__