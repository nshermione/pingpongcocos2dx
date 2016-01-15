//
//  GameSettings.h
//  pingpong
//
//  Created by Thinh Tran on 1/11/16.
//
//

#ifndef GameSettings_h
#define GameSettings_h

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

START_GAME_NS

class GameSettings {
public:
    GameSettings();
    ~GameSettings();
    
    static GameSettings* getInstance();
    
    void flush();
    bool isFirstTime();
    void markFirstTime();
    
    void savePlayer(Player* player);
    void loadPlayer(Player* player);
    
    Value get(std::string const& key);
    void set(std::string const& key, Value value);
    
private:
    static GameSettings* instance;
    ValueMap data;
    std::string filePath;
};

END_GAME_NS

#endif /* GameSettings_h */
