//
//  GameObjectPool.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/21/16.
//
//

#include "GameObjectPool.h"


START_GAME_NS

GameObjectPool* GameObjectPool::_instance = nullptr;

GameObjectPool* GameObjectPool::getInstance() {
    if (_instance == nullptr) {
        _instance = new GameObjectPool();
    }
    return _instance;
}

void GameObjectPool::add(GameObject* obj) {
    _objects[obj->getName()] = obj;
}

void GameObjectPool::remove(GameObject* obj) {
    removeAndCleanup(obj, true);
}

void GameObjectPool::removeAndCleanup(GameObject* obj, bool cleanup) {
    if (_objects.count(obj->getName()) > 0) {
        _objects.erase(obj->getName());
        if (cleanup) {
            delete obj;
        }
    }
}

GameObject* GameObjectPool::find(std::string objName) {
    if (_objects.count(objName) > 0) {
        return _objects[objName];
    }
    
    return nullptr;
}

END_GAME_NS