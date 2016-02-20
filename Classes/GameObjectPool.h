//
//  GameObjectPool.h
//  pingpong
//
//  Created by Thinh Tran on 2/21/16.
//
//

#ifndef GameObjectPool_h
#define GameObjectPool_h

#include "GameMacro.h"
#include "GameObject.h"

START_GAME_NS

class GameObjectPool {
public:
    static GameObjectPool* getInstance();
    void add(GameObject* obj);
    void remove(GameObject* obj);
    void removeAndCleanup(GameObject* obj, bool cleanup);
    GameObject* find(std::string objName);
    
private:
    static GameObjectPool* _instance;
    std::unordered_map<std::string, GameObject*> _objects;
};

END_GAME_NS

#endif /* GameObjectPool_h */
