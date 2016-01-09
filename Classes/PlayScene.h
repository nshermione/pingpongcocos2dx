#ifndef __Play_SCENE_H__
#define __Play_SCENE_H__

#include "BaseScene.h"


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
    void updateClockUI();
    
};

#endif // __Play_SCENE_H__
