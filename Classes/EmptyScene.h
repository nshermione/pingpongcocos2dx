#ifndef __EMPTY_SCENE_H__
#define __EMPTY_SCENE_H__

#include "cocos2d.h"


class Empty : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Empty);
};

#endif // __EMPTY_SCENE_H__
