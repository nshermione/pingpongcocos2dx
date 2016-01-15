//
//  GameSettings.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/11/16.
//
//

#include "GameSettings.h"


START_GAME_NS

const std::string FIRST_TIME_KEY = "first_time";
const std::string PLAYER_KEY = "player";
const std::string SETTING_FILE = "gamesettings.plist";

GameSettings *GameSettings::instance = 0;

// MacOS path for simulator : /Users/thinhtran/Library/Developer/CoreSimulator/Devices

GameSettings::GameSettings() {
    filePath = FileUtils::getInstance()->getWritablePath() + SETTING_FILE;
    data = FileUtils::getInstance()->getValueMapFromFile(filePath);
    if (data.find(FIRST_TIME_KEY) == data.end()) {
        data[FIRST_TIME_KEY] = true;
    }
    
    if (data.find(PLAYER_KEY) == data.end()) {
        ValueMap playerMap;
        data[PLAYER_KEY] = playerMap;
    
    }
}

GameSettings::~GameSettings() {
    FileUtils::getInstance()->writeValueMapToFile(data, filePath);
    delete GameSettings::instance;
}

GameSettings* GameSettings::getInstance() {
    if (!GameSettings::instance) {
        GameSettings::instance = new GameSettings();
    }
    
    return GameSettings::instance;
}

Value GameSettings::get(std::string const& key) {
    if (data.find(key) == data.end()) {
        return data[key];
    }
    
    return Value::Null;
}

void GameSettings::set(const std::string &key, cocos2d::Value value) {
    data[key] = value;
}

bool GameSettings::isFirstTime() {
    return data[FIRST_TIME_KEY].asBool() == true;
}

void GameSettings::markFirstTime() {
    data[FIRST_TIME_KEY] = false;
}

void GameSettings::flush() {
    FileUtils::getInstance()->writeValueMapToFile(data, filePath);
}

void GameSettings::savePlayer(Player *player) {
    auto playerMap = player->getSaveData();
    auto saveMap = data.at(PLAYER_KEY).asValueMap();
    
    for ( auto it = playerMap.begin(); it != playerMap.end(); ++it ) {
        auto key = it->first;
        auto value = it->second;
        saveMap[key] = value;
    }
    data[PLAYER_KEY] = saveMap;
}

void GameSettings::loadPlayer(Player *player) {
    auto playerMap = data.at(PLAYER_KEY).asValueMap();
    player->loadSavedData(playerMap);
}

END_GAME_NS
