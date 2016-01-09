//
//  Player.h
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#ifndef Player_h
#define Player_h

#include "GameObject.h"

class Player : public GameObject {
    
public:
    
    bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(Player);
    
private:
    
};

#endif /* Player_h */
