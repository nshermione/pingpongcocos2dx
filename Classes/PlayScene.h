#ifndef __Play_SCENE_H__
#define __Play_SCENE_H__

#include "game.h"
#include "Table.h"
#include "Ball.h"
#include "Block.h"
#include "Chump.h"
#include "Goal.h"
#include "Portal.h"



class Play : public BaseScene
{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_PHYSIC_SCENE(Play, "PlayScene.csb");
    
protected:
    bool init(std::string csbFile);
    void setupPhysicsWorld(cocos2d::Scene *scene);
    
private:
    void goToPauseScene();
    void goToGameOverScene();
    
    // UI
    void updatePlayerUI();
    void updateClockUI(float dt);
    
    cocos2d::Scene* _scene;
    
    PlayClock playClock;
    Table table;
    Ball ball;
    
    Block playerBlock;
    Block enemyBlock;
    
    Chump playerChump;
    Chump enemyChump;
    
    Goal playerGoal;
    Goal enemyGoal;
    
    Portal playerPortal;
    Portal enemyPortal;
    
};

#endif // __Play_SCENE_H__
