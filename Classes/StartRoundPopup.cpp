//
//  StartRoundPopup.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/20/16.
//
//

#include "StartRoundPopup.h"

USING_NS_CC;

bool StartRoundPopup::init(std::string csbFile) {
    BaseScene::init(csbFile);
    
    return true;
}

void StartRoundPopup::start() {
    auto fadeIn = FadeIn::create(1.0f);
    auto fadeOut = FadeOut::create(1.0f);
    auto closeDialog = CallFuncN::create([this] (Node* node) {
        this->close();
    });
    
    _rootNode->runAction(
                         Sequence::create(
                                          fadeIn,
                                          fadeOut,
                                          closeDialog, NULL)
    );
    
}
