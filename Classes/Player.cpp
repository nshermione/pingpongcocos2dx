//
//  Player.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#include "Player.h"

Player* Player::_instance = 0;

Player::Player() {
}

Player::~Player() {
}


Player* Player::getInstance() {
    if (!_instance) {
        _instance = new Player();
    }
    
    return _instance;
}

ValueMap const& Player::getSaveData() {
    _saveData["name"] = name;
    return _saveData;
}

void Player::loadSavedData(ValueMap const& savedData) {
    if (savedData.find("name") != savedData.end()) {
        name = savedData.at("name").asString();
    }
}