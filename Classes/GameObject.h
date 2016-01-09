//
//  GameObject.h
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#ifndef GameObject_h
#define GameObject_h

#include "cocos2d.h"

class GameObject : public cocos2d::Ref {
    
public:
    
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC(GameObject);
protected:
    virtual bool init();
    
private:
    
};

#endif /* GameObject_h */
