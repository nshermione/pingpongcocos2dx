//
//  Match.h
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#ifndef Match_h
#define Match_h

#include "cocos2d.h"
#include "Round.h"

START_GAME_NS

class Match {
public:
    Match();
    ~Match();
    
    static Match* getInstance();
    
    void init(std::string name, cocos2d::Node* rootNode);
    void startNewRound();
    void endRound(std::string goalName);
    void pause();
    void resume();
    
private:
    bool isGameEnded();
    bool isFiveRoundWinInSeries();
    
    std::shared_ptr<Round> _round;
    bool _isFiveRoundFlag;
    std::string _playerTeam;
    std::string _enemyTeam;
    cocos2d::Node* _rootNode;
    
    
    static Match* _instance;
    int _playerPoint;
    int _enemyPoint;
};

END_GAME_NS

#endif /* Match_h */
