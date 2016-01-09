#include "SplashScene.h"
#include "MainMenuScene.h"

LoadingBar* loadingBar;

// on "init" you need to initialize your instance
bool Splash::init(std::string csbFile)
{
    BaseScene::init(csbFile);
    loadingBar = (LoadingBar *)rootNode->getChildByName("loadingBar");
    this->schedule(schedule_selector(Splash::updateProgress), 0.01f);

    return true;
}

void Splash::nextScene(float dt) {
    Director::getInstance()->replaceScene(MainMenu::createScene());
}

float counter = 0;
void Splash::updateProgress(float dt) {
    counter++;
    if (counter > 100)
    {
        unschedule(schedule_selector(Splash::updateProgress));
        this->scheduleOnce(schedule_selector(Splash::nextScene), 0.05f);
    }
    loadingBar->setPercent(counter);
}



