#ifndef __MainMenu_SCENE_H__
#define __MainMenu_SCENE_H__

#include "BaseScene.h"

using namespace cocos2d::ui;

class MainMenu : public BaseScene {
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(MainMenu, "MainMenuScene.csb");
    
protected:
    bool init(std::string csbFile);
    
private:
    void quitGame();
    void playGame();
    void settings();
};

#endif // __MainMenu_SCENE_H__
