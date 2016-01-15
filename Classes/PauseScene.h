#ifndef __Pause_SCENE_H__
#define __Pause_SCENE_H__

#include "game.h"

USING_NS_GAME;

class Pause : public BaseScene{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(Pause, "PauseScene.csb");
    
protected:
    bool init(std::string csbFile);
    
private:
    void resumeGame();
    void quitGame();
    void goToMainMenu();
};

#endif // __Pause_SCENE_H__
