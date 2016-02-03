#include "PlayScene.h"
#include "PauseScene.h"

USING_NS_GAME;
USING_NS_CC;
USING_NS_CC_UI;

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
    std::vector<Sprite *> sprites;
    auto edge1 = (Sprite *) _rootNode->getChildByName("edge1");
    auto edge2 = (Sprite *) _rootNode->getChildByName("edge2");
    auto edge3 = (Sprite *) _rootNode->getChildByName("edge3");
    auto edge4 = (Sprite *) _rootNode->getChildByName("edge4");
    sprites.push_back(edge1);
    sprites.push_back(edge2);
    sprites.push_back(edge3);
    sprites.push_back(edge4);
    table.init(sprites);
    
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
    purpleChump.init(chump);
    
    chump = (Sprite *) _rootNode->getChildByName("blueChump");
    blueChump.init(chump);
    
    // init goals
    auto goal = (Sprite *) _rootNode->getChildByName("purpleGoal");
    purpleGoal.init(goal);
    
    goal = (Sprite *) _rootNode->getChildByName("blueGoal");
    blueGoal.init(goal);
    
    return true;
}

void Play::setupPhysicsWorld(Scene *scene) {


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

