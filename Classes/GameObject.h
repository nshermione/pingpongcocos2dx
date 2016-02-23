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
#include "SimpleAudioEngine.h"

#include "GameMacro.h"
#include "Physics.h"

START_GAME_NS

class GameObject {
    
public:
    GameObject();
    ~GameObject();
    
    virtual void init(std::string name);
    virtual void release();
    virtual void pause();
    virtual void resume();

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
    Physics2DBody *_physicsBody;
};


END_GAME_NS

#endif /* GameObject_h */
