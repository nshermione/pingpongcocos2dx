//
//  GameObject.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#include "GameObject.h"


bool GameObject::init() {
    // Init start
    
    // Init end
    return true;
}


/**
 * Getters & Setters
 */

// NAME
void GameObject::setName(std::string const& name) {
    this->_name = name;
}

std::string const&  GameObject::getName() {
    return this->_name;
}