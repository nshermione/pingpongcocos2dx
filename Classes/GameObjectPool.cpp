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

void GameObjectPool::removeAll() {
    for (auto it = _objects.begin(); it != _objects.end(); ++it) {
        auto obj = it->second;
        obj = nullptr;
    }
    _objects.clear();
}

void GameObjectPool::removeAndCleanup(GameObject* obj, bool cleanup) {
    if (_objects.count(obj->getName()) > 0) {
        _objects.erase(obj->getName());
        if (cleanup) {
            obj = nullptr;
        }
    }
}

GameObject* GameObjectPool::find(std::string objName) {
    if (_objects.count(objName) > 0) {
        return _objects[objName];
    }
    
    return nullptr;
}

void GameObjectPool::map(std::function<void(GameObject*)> mapFunction) {
    for (auto it = _objects.begin(); it != _objects.end(); it++) {
        try {
            auto obj = it->second;
            mapFunction(obj);
        } catch (std::exception e) {
            cocos2d::log("Unhandle Exception: %s", e.what());
            continue;
        }
    }
}

END_GAME_NS