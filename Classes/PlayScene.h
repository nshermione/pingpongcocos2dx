#ifndef __Play_SCENE_H__
#define __Play_SCENE_H__

#include "game.h"
#include "Table.h"
#include "Ball.h"

USING_NS_GAME;

class Play : public BaseScene
{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_PHYSIC_SCENE(Play, "PlayScene.csb");
    
protected:
    bool init(std::string csbFile);
    void setupPhysicsWorld(Scene *scene);
    
private:
    void goToPauseScene();
    void goToGameOverScene();
    
    // UI
    void updatePlayerUI();
    void updateClockUI(float dt);
    
    PlayClock playClock;
    Table table;
    Ball ball;
};

#endif // __Play_SCENE_H__
