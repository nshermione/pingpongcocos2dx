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

#include "GameMacro.h"

USING_NS_CC;

START_GAME_NS

class GameObject {
    
public:
    GameObject();
    GameObject(Sprite* sprite);
    ~GameObject();

    /* 
     Properties
     */
    
    // Name
    const std::string& getName();
    void setName(const std::string& name);
    
    // Sprite
    Sprite* getSprite();
    void setSprite(Sprite* sprite);

protected:
    Sprite* _sprite;
    std::string _name;
};

END_GAME_NS

#endif /* GameObject_h */
