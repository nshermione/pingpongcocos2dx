#ifndef __Splash_SCENE_H__
#define __Splash_SCENE_H__

#include "cocos2d.h"


class Splash : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Splash);
   
private:
    void nextScene(float dt);
    void updateProgress(float dt);
};

#endif // __Splash_SCENE_H__
