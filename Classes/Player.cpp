//
//  Player.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#include "Player.h"

START_GAME_NS

std::shared_ptr<Player> Player::_instance = nullptr;

Player::Player() {
}

Player::~Player() {
}


Player* Player::getInstance() {
    if (!_instance) {
        _instance = std::make_shared<Player>();
    }
    
    return _instance.get();
}

cocos2d::ValueMap const& Player::getSaveData() {
    _saveData["name"] = _name;
    return _saveData;
}

void Player::loadSavedData(cocos2d::ValueMap const& savedData) {
    if (savedData.find("name") != savedData.end()) {
        _name = savedData.at("name").asString();
    }
}

const std::string& Player::getName() {
    return _name;
}

void Player::setName(const std::string &name) {
    _name = name;
}

END_GAME_NS