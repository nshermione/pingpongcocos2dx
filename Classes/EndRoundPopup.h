//
//  EndRoundPopup.h
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#ifndef EndRoundPopup_h
#define EndRoundPopup_h

#include "game.h"

USING_NS_GAME;

class EndRoundPopup : public Popup {
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(EndRoundPopup, "EndRoundPopup.csb");
    void start(int gold, int star);
    
protected:
    bool init(std::string csbFile);
    
private:

};

#endif /* EndRoundPopup_h */
