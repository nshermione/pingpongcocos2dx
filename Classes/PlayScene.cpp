#include "PlayScene.h"
#include "PauseScene.h"
#include "Player.h"
#include "Table.h"

// on "init" you need to initialize your instance
bool Play::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("menuButton", CC_CALLBACK_0(Play::goToPauseScene, this));
    
    // set player name
    auto playerLabel = (ui::Text *) _rootNode->getChildByName("playerName");
    auto playerName = Player::getInstance()->name;
    playerLabel->setString(playerName);
    
    // init clock
    this->schedule(schedule_selector(Play::updateClockUI), 1.0f);
    playClock.start();
    
    // init table
    auto tableSprite = (Sprite *) _rootNode->getChildByName("table");
    table = std::make_shared<Table>();
    
    // TODO: fix bug - sprite of table is weird in scheduler
    table->setSprite(tableSprite);
    
    return true;
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

