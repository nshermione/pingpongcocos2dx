//
//  Popup.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#include "Popup.h"

START_GAME_NS

void Popup::pauseRecursive(cocos2d::Node* _node, bool _pause)
{
    try {
        if(_pause)
            _node->pause();
        else
            _node->resume();
        
        for (auto child: _node->getChildren())
        {
            pauseRecursive(child, _pause);
        }
    } catch (int e) {
        // ignore
    }
}

void Popup::open(cocos2d::Node *parent) {
    _parent = parent;
    pauseRecursive(_parent, true);
    _parent->addChild(this);
}

void Popup::close() {
    pauseRecursive(_parent, false);
    _parent->removeChild(this);
    _parent = nullptr;
    
    if (onClose != nullptr) {
        onClose();
    }
}


END_GAME_NS
