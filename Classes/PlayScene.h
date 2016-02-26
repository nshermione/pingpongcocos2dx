#ifndef __Play_SCENE_H__
#define __Play_SCENE_H__

#include "game.h"
#include "Match.h"



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
    void onEnterTransitionDidFinish();
    
    // UI
    void updatePlayerUI();
    
    cocos2d::Scene* _scene;
    Match* match;
    
};

#endif // __Play_SCENE_H__
