#include "PlayScene.h"
#include "PauseScene.h"

USING_NS_GAME;
USING_NS_CC;
USING_NS_CC_UI;

using namespace CocosDenshion;

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
    auto tableSprite = (Sprite *) _rootNode->getChildByName("bg");
    table.init(tableSprite);
    
    // init ball
    auto ballSprite = (Sprite *) _rootNode->getChildByName("ball");
    ball.init(ballSprite);
    
    // init blocks
    auto block = (Sprite *) _rootNode->getChildByName("purbleBlock");
    purpleBlock.init(block);
    
    block = (Sprite *) _rootNode->getChildByName("blueBlock");
    blueBlock.init(block);
    
    // init chumps
    auto chump = (Sprite *) _rootNode->getChildByName("purpleChump");
    purpleChump.init(chump, false);
    purpleChump.registerTouchEvents();
    
    chump = (Sprite *) _rootNode->getChildByName("blueChump");
    blueChump.init(chump, true);
    blueChump.registerTouchEvents();
    
    // init goals
    auto goal = (Sprite *) _rootNode->getChildByName("purpleGoal");
    purpleGoal.init(goal);
    
    goal = (Sprite *) _rootNode->getChildByName("blueGoal");
    blueGoal.init(goal);
    
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

