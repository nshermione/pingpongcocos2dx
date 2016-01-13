//
//  Table.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef Table_h
#define Table_h

#include "GameObject.h"
#include "GameMacro.h"

class Table: public GameObject {
public:
    
    void setSprite(Sprite* sprite);
    Sprite* getSprite();
    
protected:
    Sprite *sprite;
};

#endif /* Table_h */
