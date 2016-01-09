//
//  Player.h
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#ifndef Player_h
#define Player_h

#include "cocos2d.h"

class Player : public cocos2d::Ref {
    
public:
    
    virtual bool init();
    
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC(Player);
    
private:
    
};

#endif /* Player_h */
