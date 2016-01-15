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

START_GAME_NS

class PlayClock {
public:
    PlayClock();
    ~PlayClock();

    void reset();
    void start();
    void pause();
    
    float totalTime;
    void update(float deltaTime);
    
protected:
    bool _paused;
};

END_GAME_NS

#endif /* PlayClock_h */
