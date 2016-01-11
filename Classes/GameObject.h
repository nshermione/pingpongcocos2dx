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

USING_NS_CC;

class GameObject : public Ref {
    
public:
    GameObject();
    ~GameObject();

    // Properties
    std::string name;
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameObject);
    
protected:
    virtual bool init();

    
};

#endif /* GameObject_h */
