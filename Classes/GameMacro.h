//
//  GameMacro.h
//  pingpong
//
//  Created by Thinh Tran on 1/10/16.
//
//

/** @def CREATE_FUNC(__TYPE__)
 * Define a create function for a specific type, such as Layer.
 *
 * @param __TYPE__  class type to add create(), such as Layer.
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


#endif /* GameMacro_h */
