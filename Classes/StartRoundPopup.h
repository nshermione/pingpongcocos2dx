//
//  StartRoundPopup.h
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#ifndef StartRoundPopup_h
#define StartRoundPopup_h

#include "game.h"

USING_NS_GAME;

class StartRoundPopup : public Popup {
public:
    // implement the "static create()" and "static createScene()" methods manually
    CREATE_FUNC_SCENE(StartRoundPopup, "StartRoundPopup.csb");
    void start();
    
protected:
    bool init(std::string csbFile);
    
private:

};

#endif /* StartRoundPopup_h */
