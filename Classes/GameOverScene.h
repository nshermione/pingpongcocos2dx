#ifndef __GameOver_SCENE_H__
#define __GameOver_SCENE_H__

#include "BaseScene.h"


class GameOver : public BaseScene
{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(GameOver, "GameOverScene.csb");
    
protected:
    bool init(std::string csbFile);
    
private:
    void retryGame();
    void goToMainMenu();
};

#endif // __GameOver_SCENE_H__
