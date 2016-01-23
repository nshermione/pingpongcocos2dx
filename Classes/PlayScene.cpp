#include "PlayScene.h"
#include "PauseScene.h"

USING_NS_GAME;

// on "init" you need to initialize your instance
bool Play::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("menuButton", CC_CALLBACK_0(Play::goToPauseScene, this));
    
    // set player name
    auto playerLabel = (ui::Text *) _rootNode->getChildByName("purpleName");
    auto playerName = Player::getInstance()->getName();
    playerLabel->setString(playerName);
    
    // init clock
    this->schedule(schedule_selector(Play::updateClockUI), 1.0f);
    playClock.start();
    
    // init table
    auto tableSprite = (Sprite *) _rootNode->getChildByName("table");
    table.init(tableSprite);
    
    // init ball
    auto ballSprite = (Sprite *) _rootNode->getChildByName("ball");
    ball.init(ballSprite);
    
    return true;
}

void Play::setupPhysicsWorld(Scene *scene) {
    auto physicsWorld = scene->getPhysicsWorld();
//    physicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
//    physicsWorld->setAutoStep(false);
//    physicsWorld->setSubsteps(3);
//    physicsWorld->step(0.032);
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

