//
//  Match.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#include "Match.h"
#include "EndRoundPopup.h"
#include "StartRoundPopup.h"

USING_NS_CC;

START_GAME_NS

Match* Match::_instance = nullptr;

Match::Match()
:_isFiveRoundFlag(false)
,_playerTeam("")
,_playerPoint(0)
,_enemyTeam("")
,_enemyPoint(0)
{
    
}

Match::~Match() {
    
}

Match* Match::getInstance() {
    if (_instance == nullptr) {
        _instance = new Match();
    }
    
    return _instance;
}

void Match::init(std::string name, cocos2d::Node* rootNode) {
    _rootNode = rootNode;
    
    // random team
    _playerTeam = "purple";
    _enemyTeam = "blue";
    if (random(0, 1) == 0) {
        _playerTeam = "blue";
        _enemyTeam = "purple";
    }
}


void Match::endRound(std::string goalName) {
    int gold = 0;
    int star = 0;
    
    if (goalName.find(_playerTeam) == std::string::npos) {
        // win
        gold = 50;
        star = 20;
        _playerPoint++;
        
        // play sound yay
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
        audio->playEffect("yay.wav");
    } else {
        // lose
        star = -15;
        _enemyPoint++;
        
        // play sound
        auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
        audio->playEffect("boo.wav");
    }
    
    // update score
    auto playerScore = (ui::Text *) _rootNode->getChildByName(_playerTeam + "Score");
    auto enemyScore = (ui::Text *) _rootNode->getChildByName(_enemyTeam + "Score");
    playerScore->setString(std::to_string(_playerPoint));
    enemyScore->setString(std::to_string(_enemyPoint));
    
    // open endround popup then start new round
    auto endRoundPopup = EndRoundPopup::create();
    auto scene = Director::getInstance()->getRunningScene();
    endRoundPopup->open(scene);
    endRoundPopup->start(gold, star);
    endRoundPopup->onClose = [this] () {
        _round->end();
        // wait 1 second to have all physicsBody removed
        _rootNode->scheduleOnce([this](float dt) {
            this->startNewRound();
        }, 1, "start new round");
        
    };
}

void Match::startNewRound() {
    _round = std::make_shared<Round>();
    _round->init("round", _rootNode, _playerTeam, _enemyTeam);
    
    // Pause
    pause();
    
    // New round Animation
    auto startRoundPopup = StartRoundPopup::create();
    auto scene = Director::getInstance()->getRunningScene();
    startRoundPopup->open(scene);
    startRoundPopup->start();
    startRoundPopup->onClose = [this] () {
        // Resume
        resume();
    };
    
}

void Match::pause() {
    _rootNode->pause();
    _round->pause();
}

void Match::resume() {
    _round->resume();
    _rootNode->resume();
}

END_GAME_NS