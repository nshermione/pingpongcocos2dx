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
    
    cocos2d::Value get(std::string const& key);
    void set(std::string const& key, cocos2d::Value value);
    
private:
    static GameSettings* instance;
    cocos2d::ValueMap data;
    std::string filePath;
};

END_GAME_NS

#endif /* GameSettings_h */
