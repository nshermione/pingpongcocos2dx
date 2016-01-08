#ifndef __Pause_SCENE_H__
#define __Pause_SCENE_H__

#include "cocos2d.h"


class Pause : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Pause);
};

#endif // __Pause_SCENE_H__
