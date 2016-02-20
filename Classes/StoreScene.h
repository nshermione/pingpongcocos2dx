#ifndef __Store_SCENE_H__
#define __Store_SCENE_H__

#include "game.h"

USING_NS_GAME;

class Store : public BaseScene {
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(Store, "StoreScene.csb");
    
protected:
    bool init(std::string csbFile);
    
    void backToHome();
};

#endif // __Store_SCENE_H__
