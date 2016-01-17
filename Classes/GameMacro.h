//
//  GameMacro.h
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

#include <stdio.h>
#include <iostream>
#include <memory>

/** Namespace
 * Define game namespace and using game namespace
 *
 */
#define START_GAME_NS namespace game {

#define END_GAME_NS }

#define USING_NS_GAME using namespace game

#define USING_NS_CC_UI using namespace cocos2d::ui


/** @def CREATE_FUNC_SCENE(__TYPE__, csbFile)
 * Define a create function for a specific type, such as Layer.
 *
 * @param __TYPE__  class type to add create() and createScene(), such as Layer.
 */
#ifndef GameMacro_h
#define GameMacro_h

#define CREATE_FUNC_SCENE(__TYPE__,csbFile) \
static __TYPE__* create() \
{ \
__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
if (pRet && pRet->init( (csbFile) )) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = nullptr; \
return nullptr; \
} \
} \
static Scene* createScene() \
{ \
    Scene* scene = Scene::create(); \
    __TYPE__* layer = __TYPE__::create(); \
    scene->addChild(layer); \
    return scene; \
}


/** @def CREATE_FUNC_PHYSIC_SCENE(__TYPE__, csbFile)
 * Define a create function for a specific type, such as Layer.
 *
 * @param __TYPE__  class type to add create() and createScene(), such as Layer.
 */
#define CREATE_FUNC_PHYSIC_SCENE(__TYPE__,csbFile) \
static __TYPE__* create() \
{ \
__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
if (pRet && pRet->init( (csbFile) )) \
{ \
pRet->autorelease(); \
return pRet; \
} \
else \
{ \
delete pRet; \
pRet = nullptr; \
return nullptr; \
} \
} \
static Scene* createScene() \
{ \
Scene* scene = Scene::createWithPhysics(); \
__TYPE__* layer = __TYPE__::create(); \
layer->setupPhysicsWorld(scene);\
scene->addChild(layer); \
return scene; \
}





// Global functions
template<typename ... Args>
std::string string_snprintf(const std::string &pattern, Args ... args) {
    size_t size = snprintf( nullptr, 0, pattern.c_str(), args ... ) + 1; // Extra space for '\0'
    std::unique_ptr<char[]> buf( new char[ size ] );
    snprintf( buf.get(), size, pattern.c_str(), args ... );
    return std::string( buf.get(), buf.get() + size - 1 );
}

#endif /* GameMacro_h */
