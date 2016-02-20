//
//  GameObject.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#include "GameObject.h"
#include "GameObjectPool.h"

START_GAME_NS

GameObject::GameObject()
:_name("")
,_sprite(NULL){
    
}

GameObject::~GameObject() {
}

void GameObject::init(std::string name) {
    setName(name);
    GameObjectPool::getInstance()->add(this);
}

void GameObject::release() {
    GameObjectPool::getInstance()->removeAndCleanup(this, true);
}

const std::string& GameObject::getName() {
    return _name;
}

void GameObject::setName(const std::string &name) {
    _name = name;
}

cocos2d::Sprite* GameObject::getSprite() {
    return _sprite;
}

void GameObject::setSprite(cocos2d::Sprite *sprite) {
    _sprite = sprite;
}

END_GAME_NS

