#ifndef __GameOver_SCENE_H__
#define __GameOver_SCENE_H__

#include "cocos2d.h"


class GameOver : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);
    
private:
    void bindButtons(Node* rootNode);
    void retryGame();
    void goToMainMenu();
};

#endif // __GameOver_SCENE_H__
