#ifndef __Splash_SCENE_H__
#define __Splash_SCENE_H__

#include "cocos2d.h"
#include "BaseScene.h"


class Splash : public BaseScene
{
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(Splash, "SplashScene.csb");
    
protected:
    bool init(std::string csbFile);
   
private:
    void nextScene(float dt);
    void updateProgress(float dt);
};

#endif // __Splash_SCENE_H__
