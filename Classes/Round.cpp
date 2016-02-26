//
//  Round.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#include "Round.h"
#include "GameObjectPool.h"

USING_NS_CC;

START_GAME_NS

Round::Round()
:onStart(nullptr)
,onEnd(nullptr)
,onPause(nullptr)
,onResume(nullptr) {
    
}

Round::~Round() {
    
}

void Round::init(std::string name, cocos2d::Node* rootNode, std::string playerTeam, std::string enemyTeam) {
    _rootNode = rootNode;
    
    // set player name
    auto playerLabel = (cocos2d::ui::Text *) rootNode->getChildByName(playerTeam + "Name");
    auto playerName = Player::getInstance()->getName();
    playerLabel->setString(playerName);
    
    // init clock
    playClock.init(1.0f);
    rootNode->addChild(playClock.getSprite());
    rootNode->schedule(CC_CALLBACK_1(Round::updateClockUI, this), 1.0f, "updateClockUI");
    playClock.start();
    
    // init table
    auto tableSprite = (Sprite *) rootNode->getChildByName("bg");
    table.init(tableSprite, "bg" );
    
    // init ball
    spawnBall();
    
    // init blocks
    auto block = (Sprite *) rootNode->getChildByName(playerTeam + "Block");
    playerBlock.init(block, playerTeam + "Block");
    
    block = (Sprite *) rootNode->getChildByName(enemyTeam + "Block");
    enemyBlock.init(block, enemyTeam + "Block");
    
    // init portals
    auto pPortal = (Sprite *) rootNode->getChildByName(playerTeam + "Portal");
    auto pPortalCollider = (Sprite *) rootNode->getChildByName(playerTeam + "PortalCollider");
    auto ePortal = (Sprite *) rootNode->getChildByName(enemyTeam + "Portal");
    auto ePortalCollider = (Sprite *) rootNode->getChildByName(enemyTeam + "PortalCollider");
    
    playerPortal.init(pPortal, playerTeam + "Portal", ePortal, pPortalCollider);
    enemyPortal.init(ePortal, enemyTeam + "Portal", pPortal, ePortalCollider);
    
    // init chumps
    auto botEdge = (Sprite *) rootNode->getChildByName("botEdge");
    auto topEdge = (Sprite *) rootNode->getChildByName("topEdge");
    auto chump = (Sprite *) rootNode->getChildByName(playerTeam + "Chump");
    playerChump.init(chump, playerTeam + "Chump", topEdge, botEdge, playerTeam=="blue", true);
    
    chump = (Sprite *) rootNode->getChildByName(enemyTeam + "Chump");
    enemyChump.init(chump, enemyTeam + "Chump", topEdge, botEdge, enemyTeam=="blue", false);
    
    // init goals
    auto goal = (Sprite *) rootNode->getChildByName(playerTeam + "Goal");
    playerGoal.init(goal, playerTeam + "Goal");
    
    goal = (Sprite *) rootNode->getChildByName(enemyTeam + "Goal");
    enemyGoal.init(goal, enemyTeam + "Goal");
    
}


void Round::start() {
    if (onStart != nullptr) {
        onStart();
    }

    // TODO: animation for stating game
    
    
    // Resume all gameobjects
    

}

void Round::end() {
    if (onEnd != nullptr) {
        onEnd();
    }
    
    _balls.clear();
    
    GameObjectPool::getInstance()->map([this](GameObject* obj) {
        obj->getSprite()->stopAllActions();
        obj->getSprite()->unscheduleAllCallbacks();
        _rootNode->getEventDispatcher()->removeEventListenersForTarget(obj->getSprite());
    });
    
    _rootNode->stopAllActions();
    _rootNode->unscheduleAllCallbacks();
    
    
    Physics::getWorld2D()->removeAllBodies();
//
}

void Round::pause() {
    if (onPause != nullptr) {
        onPause();
    }
    
    GameObjectPool::getInstance()->map([this] (GameObject* obj) {
        obj->pause();
    });
    
    Physics::getWorld2D()->pause();
}

void Round::resume() {
    if (onResume != nullptr) {
        onResume();
    }
    
    GameObjectPool::getInstance()->map([this] (GameObject* obj) {
        obj->resume();
    });
    
    Physics::getWorld2D()->resume();
}


void Round::spawnBall() {
    auto ball = std::make_shared<Ball>();
    auto ballSprite = Sprite::create("ball.png");
    ballSprite->setScale(Director::getInstance()->getContentScaleFactor());
    ballSprite->setName("ball");
    _rootNode->addChild(ballSprite);
    
    auto startPoint = _rootNode->getChildByName("startPoint");
    ballSprite->setPosition(startPoint->getPosition());
    
    ball->init(ballSprite, "ball");
    
    _balls.push_back(ball);
}

void Round::doubleBall() {
    
}


void Round::updateClockUI(float dt) {
    playClock.update(dt);
    int minute = (int)playClock.totalTime / 60;
    int second = (int)playClock.totalTime % 60;
    auto clockText = (cocos2d::ui::Text *) _rootNode->getChildByName("clock");
    auto timeString = string_snprintf("%02d:%02d", minute, second);
    clockText->setString(timeString);
}

END_GAME_NS