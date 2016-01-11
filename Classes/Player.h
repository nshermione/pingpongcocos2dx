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

class Player {
    
public:
    Player();
    ~Player();
    
    static Player* getInstance();
    std::string name;
    
    ValueMap const& getSaveData();
    void loadSavedData(ValueMap const& savedData);
    
private:
    static Player* _instance;
    ValueMap _saveData;
};

#endif /* Player_h */
