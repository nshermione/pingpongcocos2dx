//
//  PlayClock.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef PlayClock_h
#define PlayClock_h

#include "GameMacro.h"
#include "GameObject.h"

START_GAME_NS

class PlayClock : public GameObject {
public:
    PlayClock();
    ~PlayClock();
    
    void init(float speed);

    void reset();
    void start();
    void pause();
    void resume();
    
    float totalTime;
    void update(float deltaTime);
    
protected:
    bool _paused;
    float _speed;
};

END_GAME_NS

#endif /* PlayClock_h */
