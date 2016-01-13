//
//  PlayClock.hpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#ifndef PlayClock_h
#define PlayClock_h

#include "GameObject.h"

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

#endif /* PlayClock_h */
