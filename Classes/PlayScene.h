#ifndef __Play_SCENE_H__
#define __Play_SCENE_H__

#include "cocos2d.h"


class Play : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    void goToPauseScene();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Play);
    
private:
    void bindButtons(Node* rootNode);
};

#endif // __Play_SCENE_H__
