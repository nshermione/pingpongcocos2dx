#ifndef __EnterName_SCENE_H__
#define __EnterName_SCENE_H__

#include "BaseScene.h"


class EnterName : public BaseScene {
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(EnterName, "EnterNameScene.csb");
    
protected:
    bool init(std::string csbFile);
    
private:
    void submit();
};

#endif // __EnterName_SCENE_H__
