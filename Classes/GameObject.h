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

START_GAME_NS

class GameObject {
    
public:
    GameObject();
    GameObject(cocos2d::Sprite* sprite);
    ~GameObject();

    /* 
     Properties
     */
    
    // Name
    const std::string& getName();
    void setName(const std::string& name);
    
    // Sprite
    cocos2d::Sprite* getSprite();
    void setSprite(cocos2d::Sprite* sprite);

protected:
    cocos2d::Sprite* _sprite;
    std::string _name;
};


END_GAME_NS

#endif /* GameObject_h */
