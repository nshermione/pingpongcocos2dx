#ifndef __Settings_SCENE_H__
#define __Settings_SCENE_H__

#include "game.h"

USING_NS_GAME;

class Settings : public BaseScene {
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(Settings, "SettingsScene.csb");
    
protected:
    bool init(std::string csbFile);
};

#endif // __Settings_SCENE_H__
