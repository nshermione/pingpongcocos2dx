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
    
    // schedule physics update
    this->schedule(schedule_selector(Play::physicsUpdate), 0.016f);
    
    return true;
}

float _filteredUpdateDelta = 0;

void Play::setupPhysicsWorld(Scene *scene) {
    _scene = scene;
    
}

void Play::physicsUpdate(float dt) {
    _scene->getPhysicsWorld()->setAutoStep(false);
    // How many times to supstep the phyiscs engine per game update.
    const int phyiscsSubSteps = 3;
    
    // The delta is divided by the number of substeps, to sync the game step with the physics step.
    float delta = dt / static_cast<float>(phyiscsSubSteps);
    
    _filteredUpdateDelta = delta > __FLT_EPSILON__ ? 0.15 * dt + 0.85 * _filteredUpdateDelta : 0.0;
    
    // Apply the number of substeps to the phyiscs engine for this game update.
    for (int i=phyiscsSubSteps; i>0; i--)
    {
        _scene->getPhysicsWorld()->step(_filteredUpdateDelta);
    }
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

