//
//  Player.h
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#ifndef Player_h
#define Player_h

#include "GameMacro.h"
#include "cocos2d.h"

START_GAME_NS

class Player {
public:
    Player();
    ~Player();
    
    static Player* getInstance();
    
    cocos2d::ValueMap const& getSaveData();
    void loadSavedData(cocos2d::ValueMap const& savedData);
    
    /*
     Properties
     */
    
    const std::string& getName();
    void setName(const std::string& name);
    
private:
    static Player* _instance;
    cocos2d::ValueMap _saveData;
    std::string _name;
};

END_GAME_NS

#endif /* Player_h */
