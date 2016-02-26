//
//  Round.h
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#ifndef Round_h
#define Round_h

#include "ui/CocosGUI.h"

#include "GameObject.h"
#include "PlayClock.h"
#include "Table.h"
#include "Ball.h"
#include "Block.h"
#include "Chump.h"
#include "Goal.h"
#include "Portal.h"
#include "Player.h"


START_GAME_NS

class Round {
public:
    Round();
    ~Round();
    
    void init(std::string name, cocos2d::Node* rootNodem, std::string playerTeam, std::string enemyTeam);
    
    void start();
    void end();
    void pause();
    void resume();
    
    typedef std::function<void()> onRoundCallback;
    onRoundCallback onStart;
    onRoundCallback onEnd;
    onRoundCallback onPause;
    onRoundCallback onResume;
    
private:
    void spawnBall();
    void doubleBall();
    
    std::vector<std::shared_ptr<Ball>> _balls;
    
    void goToPauseScene();
    void goToGameOverScene();
    
    // UI
    void updatePlayerUI();
    void updateClockUI(float dt);
    
    cocos2d::Node* _rootNode;
    
    PlayClock playClock;
    Table table;
    Ball ball;
    
    Block playerBlock;
    Block enemyBlock;
    
    Chump playerChump;
    Chump enemyChump;
    
    Goal playerGoal;
    Goal enemyGoal;
    
    Portal playerPortal;
    Portal enemyPortal;
};

END_GAME_NS

#endif /* Round_h */
