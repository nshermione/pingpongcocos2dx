#ifndef __Settings_SCENE_H__
#define __Settings_SCENE_H__

#include "cocos2d.h"


class Settings : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Settings);
};

#endif // __Settings_SCENE_H__
