#include "EnterNameScene.h"
#include "GameSettings.h"
#include "MainMenuScene.h"
#include "Player.h"

// on "init" you need to initialize your instance
bool EnterName::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    
    bindButton("submitButton", CC_CALLBACK_0(EnterName::submit, this));
    
    return true;
}

void EnterName::submit() {
    auto nameField = (TextField* )_rootNode->getChildByName("nameField");
    auto playerName = nameField->getString();
    Player::getInstance()->name = playerName;
    
    auto settings = GameSettings::getInstance();
    settings->savePlayer(Player::getInstance());
    settings->markFirstTime();
    settings->flush();
    
    Director::getInstance()->replaceScene(MainMenu::createScene());
}

