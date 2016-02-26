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
,_sprite(nullptr),
_physicsBody(nullptr){
    
}

GameObject::~GameObject() {
    GameObjectPool::getInstance()->remove(this);
}

void GameObject::init(std::string name) {
    setName(name);
    GameObjectPool::getInstance()->add(this);
}

void GameObject::release() {
    if (
        getSprite() != nullptr
        && ((_physicsBody != nullptr && _physicsBody->getSprite() != nullptr)
            || _physicsBody == nullptr))
        getSprite()->removeFromParent();
    
    if (_physicsBody != nullptr)
        Physics::getWorld2D()->removeBody(_physicsBody.get());
}

void GameObject::pause() {
    if (getSprite() != nullptr)
        getSprite()->pause();
    
}

void GameObject::resume() {
    if (getSprite() != nullptr)
        getSprite()->resume();
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

