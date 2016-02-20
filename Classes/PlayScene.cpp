#include "PlayScene.h"
#include "PauseScene.h"
#include "EndRoundPopup.h"

USING_NS_GAME;
USING_NS_CC;
USING_NS_CC_UI;

using namespace CocosDenshion;

// on "init" you need to initialize your instance
bool Play::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("menuButton", CC_CALLBACK_0(Play::goToPauseScene, this));
    
    // random team
    std::string playerTeam = "purple";
    std::string enemyTeam = "blue";
    if (random(0, 1) == 0) {
        playerTeam = "blue";
        enemyTeam = "purple";
    }
    
    // set player name
    auto playerLabel = (ui::Text *) _rootNode->getChildByName(playerTeam + "Name");
    auto playerName = Player::getInstance()->getName();
    playerLabel->setString(playerName);
    
    // init clock
    this->schedule(schedule_selector(Play::updateClockUI), 1.0f);
    playClock.start();
    
    // init table
    auto tableSprite = (Sprite *) _rootNode->getChildByName("bg");
    table.init(tableSprite, "bg" );
    
    // init ball
    auto ballSprite = (Sprite *) _rootNode->getChildByName("ball");
    ball.init(ballSprite, "ball" );
    
    // init blocks
    auto block = (Sprite *) _rootNode->getChildByName(playerTeam + "Block");
    playerBlock.init(block, playerTeam + "Block");
    
    block = (Sprite *) _rootNode->getChildByName(enemyTeam + "Block");
    enemyBlock.init(block, enemyTeam + "Block");
    
    // init portals
    auto pPortal = (Sprite *) _rootNode->getChildByName(playerTeam + "Portal");
    auto pPortalCollider = (Sprite *) _rootNode->getChildByName(playerTeam + "PortalCollider");
    auto ePortal = (Sprite *) _rootNode->getChildByName(enemyTeam + "Portal");
    auto ePortalCollider = (Sprite *) _rootNode->getChildByName(enemyTeam + "PortalCollider");
    
    playerPortal.init(pPortal, playerTeam + "Portal", ePortal, ballSprite, pPortalCollider);
    enemyPortal.init(ePortal, enemyTeam + "Portal", pPortal, ballSprite, ePortalCollider);
    
    // init chumps
    auto botEdge = (Sprite *) _rootNode->getChildByName("botEdge");
    auto topEdge = (Sprite *) _rootNode->getChildByName("topEdge");
    auto chump = (Sprite *) _rootNode->getChildByName(playerTeam + "Chump");
    playerChump.init(chump, playerTeam + "Chump", topEdge, botEdge, playerTeam=="blue", true);
    
    chump = (Sprite *) _rootNode->getChildByName(enemyTeam + "Chump");
    enemyChump.init(chump, playerTeam + "Chump", topEdge, botEdge, enemyTeam=="blue", false);
    
    // init goals
    auto goal = (Sprite *) _rootNode->getChildByName(playerTeam + "Goal");
    playerGoal.init(goal, playerTeam + "Goal");
    
    goal = (Sprite *) _rootNode->getChildByName(enemyTeam + "Goal");
    enemyGoal.init(goal, enemyTeam + "Goal");
    
    return true;
}

float _filteredUpdateDelta = 0;

void Play::setupPhysicsWorld(Scene *scene) {
    _scene = scene;
    
    auto world = Physics::getWorld2D();
    world->init(scene, 0.0f, 0.0f);
    
    world->drawDebug();
}

void Play::goToPauseScene() {
    auto pauseScene = Pause::createScene();
    Director::getInstance()->pushScene(pauseScene);
}

void Play::updateClockUI(float dt) {
    playClock.update(dt);
    int minute = (int)playClock.totalTime / 60;
    int second = (int)playClock.totalTime % 60;
    auto clockText = (ui::Text *) _rootNode->getChildByName("clock");
    auto timeString = string_snprintf("%02d:%02d", minute, second);
    clockText->setString(timeString);
}

