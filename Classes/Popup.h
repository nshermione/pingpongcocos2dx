//
//  Popup.h
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#ifndef Popup_h
#define Popup_h

#include "BaseScene.h"

START_GAME_NS

class Popup : public BaseScene {
public:
    virtual void open(cocos2d::Node* parent);
    virtual void close();
    std::function<void()> onClose;
    
private:
    
    void pauseRecursive(cocos2d::Node* _node, bool _pause);
    cocos2d::Node *_parent;
    
    
};

END_GAME_NS

#endif /* Popup_h */
