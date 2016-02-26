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
    match = Match::getInstance();
    match->init("match", _rootNode);
    
    return true;
}


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

void Play::onEnterTransitionDidFinish() {
    Node::onEnter();
    match->startNewRound();
    
}

