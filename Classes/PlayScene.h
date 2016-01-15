#ifndef __Play_SCENE_H__
#define __Play_SCENE_H__

#include "game.h"
#include "Table.h"

USING_NS_GAME;

class Play : public BaseScene
{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(Play, "PlayScene.csb");
    
protected:
    bool init(std::string csbFile);
    
private:
    void goToPauseScene();
    void goToGameOverScene();
    
    // UI
    void updatePlayerUI();
    void updateClockUI(float dt);
    
    PlayClock playClock;
    std::shared_ptr<Table> table;
};

#endif // __Play_SCENE_H__
