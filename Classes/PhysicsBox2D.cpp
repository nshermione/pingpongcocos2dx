//
//  PhysicsBox2D.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/11/16.
//
//

#include "PhysicsBox2D.h"
#include "Box2DContactListener.h"

START_GAME_NS

// PhysicsBox2DBody

PhysicsBox2DBody::PhysicsBox2DBody()
:deleteFlag(false)
,_name("") {
   
}

PhysicsBox2DBody::~PhysicsBox2DBody() {
}

void PhysicsBox2DBody::setDensity(float density){
    auto fixture = _body->GetFixtureList();
    fixture->SetDensity(density);
}

void PhysicsBox2DBody::setFriction(float friction){
    auto fixture = _body->GetFixtureList();
    fixture->SetFriction(friction);
}

void PhysicsBox2DBody::setRestitution(float restitution){
    auto fixture = _body->GetFixtureList();
    fixture->SetRestitution(restitution);
}
void PhysicsBox2DBody::setMaterial(float density, float friction, float restitution){
    auto fixture = _body->GetFixtureList();
    fixture->SetDensity(density);
    fixture->SetFriction(friction);
    fixture->SetRestitution(restitution);
    
}

void PhysicsBox2DBody::setGroup(int groupId){
    auto filter = _body->GetFixtureList()->GetFilterData();
    filter.groupIndex = groupId;
    _body->GetFixtureList()->SetFilterData(filter);
}

void PhysicsBox2DBody::setCategoryBitmask(int bitmask){
    auto filter = _body->GetFixtureList()->GetFilterData();
    filter.categoryBits = bitmask;
    _body->GetFixtureList()->SetFilterData(filter);
}
void PhysicsBox2DBody::setCollisionBitmask(int bitmask){
    auto filter = _body->GetFixtureList()->GetFilterData();
    filter.maskBits = bitmask;
    _body->GetFixtureList()->SetFilterData(filter);
}

void PhysicsBox2DBody::setContactTestBitmask(int bitmask){
    
}

void PhysicsBox2DBody::setDynamic(bool isDynamic){
    if (isDynamic) {
        _body->SetType(b2_dynamicBody);
    } else {
        _body->SetType(b2_staticBody);
    }
}

bool PhysicsBox2DBody::isDynamic() {
    return _body->GetType() == b2_dynamicBody;
}

void PhysicsBox2DBody::setGravity(bool inGravity) {
    if (inGravity) {
        _body->SetGravityScale(1.0f);
    } else {
        _body->SetGravityScale(0.0f);
    }
}

void PhysicsBox2DBody::setVelocity(const cocos2d::Vec2 &vel) {
    _body->SetLinearVelocity(b2Vec2(vel.x, vel.y));
}

cocos2d::Vec2 PhysicsBox2DBody::getVelocity() {
    auto vel = _body->GetLinearVelocity();
    return cocos2d::Vec2(vel.x, vel.y);
}

void PhysicsBox2DBody::setPosition(const cocos2d::Vec2 &vel) {
    auto transform = _body->GetTransform();
    _body->SetTransform(b2Vec2(vel.x/BOX2D_PTM_RATIO, vel.y/BOX2D_PTM_RATIO), transform.q.GetAngle());
}

void PhysicsBox2DBody::movePosition(const cocos2d::Vec2 &vel) {
    auto transform = _body->GetTransform();
    auto newPos = b2Vec2(transform.p.x + vel.x/BOX2D_PTM_RATIO,
                         transform.p.y + vel.y/BOX2D_PTM_RATIO);
    _body->SetTransform(newPos, transform.q.GetAngle());
    
    auto pos = _body->GetPosition();
    _bodySprite->setPosition(pos.x * BOX2D_PTM_RATIO, pos.y * BOX2D_PTM_RATIO);
}

cocos2d::Vec2 PhysicsBox2DBody::getPosition() {
    auto pos = _body->GetTransform().p;
    return cocos2d::Vec2(pos.x * BOX2D_PTM_RATIO, pos.y * BOX2D_PTM_RATIO);
}

bool PhysicsBox2DBody::isSupportCCD() {
    return true;
}

void PhysicsBox2DBody::enableCCD() {
    _body->SetBullet(true);
}

void PhysicsBox2DBody::setBody(b2Body *body) {
    _body = body;
}

b2Body* PhysicsBox2DBody::getBody() {
    return _body;
}

void PhysicsBox2DBody::setDeleteFlag(bool isDeleted) {
    deleteFlag = isDeleted;
}

bool PhysicsBox2DBody::isDeleted() {
    return deleteFlag;
}

const std::string& PhysicsBox2DBody::getName() {
    return _name;
}

void PhysicsBox2DBody::setName(const std::string& name) {
    _name = name;
}

//PhysicsBox2DContact

PhysicsBox2DContact::PhysicsBox2DContact(PhysicsBox2DWorld* world,
                                         b2Contact* contact,
                                         Physics2DBody* target) {
    bodyA = world->findBody(contact->GetFixtureA()->GetBody()).get();
    bodyB = world->findBody(contact->GetFixtureB()->GetBody()).get();
    changeTarget(target);
}

PhysicsBox2DContact::~PhysicsBox2DContact() {

}

void PhysicsBox2DContact::changeTarget(Physics2DBody* target) {
    if (target == bodyA) {
        targetBody = bodyA;
        otherBody = bodyB;
    } else if (target == bodyB) {
        targetBody = bodyB;
        otherBody = bodyA;
    } else {
        targetBody = nullptr;
        otherBody = nullptr;
    }
}

Physics2DBody* PhysicsBox2DContact::getBodyA() {
    return bodyA;
}

Physics2DBody* PhysicsBox2DContact::getBodyB() {
    return bodyB;
}

cocos2d::Sprite* PhysicsBox2DContact::getSpriteA() {
    return bodyA->getSprite();
}

cocos2d::Sprite* PhysicsBox2DContact::getSpriteB() {
    return bodyB->getSprite();
}

Physics2DBody* PhysicsBox2DContact::getTargetBody() {
    return targetBody;
}

Physics2DBody* PhysicsBox2DContact::getOtherBody() {
    return otherBody;
}

// PhysicsBox2DWorld

PhysicsBox2DWorld::PhysicsBox2DWorld()
:_world(nullptr)
,_contactListener(new Box2DContactListener(this)) {
    
}

PhysicsBox2DWorld::~PhysicsBox2DWorld() {
    SAFE_DELETE_POINTER(_world);
    SAFE_DELETE_POINTER(_contactListener);
}

void PhysicsBox2DWorld::init(cocos2d::Scene *scene, float gravityX, float gravityY) {
    Physics2DWorld::init(scene, gravityX, gravityY);
    
    b2Vec2 gravity;
    gravity.Set(gravityX, gravityY);
    
    // create a world object, which will hold and simulate the rigid bodies.
    _world = new b2World(gravity);
    _world->SetContactListener(_contactListener);
    
    // schedule physics main loop
    scene->schedule(CC_CALLBACK_1(PhysicsBox2DWorld::update, this), 0.016f, "updatePhysicsBox2dWorld");
}

void PhysicsBox2DWorld::update(float dt) {
    _world->Step(dt, 8, 3);

    for(auto it = _bodyMap.begin(); it != _bodyMap.end();) {
        auto physicsBody = (*it).second;
        if (physicsBody == nullptr) {
            _bodyMap.erase(it++);
            continue;
        }
        auto b =  physicsBody->getBody();
        // Remove deleted bodies
        if (physicsBody->isDeleted() && b->GetUserData() != NULL) {
            cocos2d::Sprite *sprite = (cocos2d::Sprite *)b->GetUserData();
            sprite->removeFromParentAndCleanup(false);
            _bodyMap.erase(it++);
            _bodyMapByName.erase(physicsBody->getName());
            _world->DestroyBody(b);
            continue;
        }
        // Move sprite
        if (b->GetUserData() != NULL) {
            cocos2d::Sprite *sprite = (cocos2d::Sprite *)b->GetUserData();
            if (physicsBody->isDynamic()) {
                auto pos = b->GetPosition();
                sprite->setPosition(pos.x * BOX2D_PTM_RATIO, pos.y * BOX2D_PTM_RATIO);
                sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
            } else {
                auto pos = sprite->getPosition();
                physicsBody->setPosition(pos);
            }
        }
        ++it;
    }
}


std::shared_ptr<Physics2DBody> PhysicsBox2DWorld::addBody(cocos2d::Sprite* sprite, const std::string &bodyName, const std::string &bodyPrototype) {
    auto loader = GB2ShapeCache::sharedGB2ShapeCache();
    auto pos = sprite->getPosition();
    b2Body *body;
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(pos.x / BOX2D_PTM_RATIO, pos.y / BOX2D_PTM_RATIO);
    bodyDef.userData = sprite;
    bodyDef.fixedRotation = true;
    body = _world->CreateBody(&bodyDef);
    loader->addFixturesToBody(body, bodyPrototype);
    
    auto pBody = std::make_shared<PhysicsBox2DBody>();
    pBody->setBody(body);
    pBody->setSprite(sprite);
    pBody->setName(bodyName);
    
    _bodyMap[body] = pBody;
    _bodyMapByName[bodyName] = pBody;
    return pBody;
}

std::shared_ptr<Physics2DBody> PhysicsBox2DWorld::addBodyBox(cocos2d::Sprite* sprite,
                          const std::string &bodyName,
                          const cocos2d::Size& size,
                          cocos2d::PhysicsMaterial material) {
    auto pos = sprite->getPosition();
    
    b2Body *body;
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(pos.x / BOX2D_PTM_RATIO, pos.y / BOX2D_PTM_RATIO);
    bodyDef.linearDamping = 0.0f;
    bodyDef.angularDamping = 0.01f;
    bodyDef.gravityScale = 0.0f;
    bodyDef.userData = sprite;
    body = _world->CreateBody(&bodyDef);
    
    b2PolygonShape polygon;
    polygon.SetAsBox(sprite->getContentSize().width / BOX2D_PTM_RATIO, sprite->getContentSize().height / BOX2D_PTM_RATIO);
    b2FixtureDef paddleShapeDef;
    paddleShapeDef.shape = &polygon;
    paddleShapeDef.density = material.density;
    paddleShapeDef.friction = material.friction;
    paddleShapeDef.restitution = material.restitution;
    
    b2Fixture *_paddleFixture;
    _paddleFixture = body->CreateFixture(&paddleShapeDef);
    
    auto pBody = std::make_shared<PhysicsBox2DBody>();
    pBody->setBody(body);
    pBody->setSprite(sprite);
    pBody->setName(bodyName);
    
    _bodyMap[body] = pBody;
    _bodyMapByName[bodyName] = pBody;
    return pBody;
}

std::shared_ptr<Physics2DBody> PhysicsBox2DWorld::addBodyCircle(cocos2d::Sprite* sprite,
                             const std::string &bodyName,
                             float radius,
                             cocos2d::PhysicsMaterial material)  {
    auto pos = sprite->getPosition();
    
    b2Body *body;
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(pos.x / BOX2D_PTM_RATIO, pos.y / BOX2D_PTM_RATIO);
    bodyDef.linearDamping = 0.0f;
    bodyDef.angularDamping = 0.01f;
    bodyDef.gravityScale = 0.0f;
    bodyDef.userData = sprite;
    body = _world->CreateBody(&bodyDef);
    
    b2CircleShape circle;
    circle.m_p.Set(sprite->getContentSize().width/2 / BOX2D_PTM_RATIO, sprite->getContentSize().height/2 / BOX2D_PTM_RATIO);
    circle.m_radius = sprite->getContentSize().width/2;
    b2FixtureDef paddleShapeDef;
    paddleShapeDef.shape = &circle;
    paddleShapeDef.density = material.density;
    paddleShapeDef.friction = material.friction;
    paddleShapeDef.restitution = material.restitution;
    
    b2Fixture *_paddleFixture;
    _paddleFixture = body->CreateFixture(&paddleShapeDef);
    
    auto pBody = std::make_shared<PhysicsBox2DBody>();
    pBody->setBody(body);
    pBody->setSprite(sprite);
    pBody->setName(bodyName);
    
    _bodyMap[body] = pBody;
    _bodyMapByName[bodyName] = pBody;
    return pBody;
}

void PhysicsBox2DWorld::removeBody(Physics2DBody *body) {
    ((PhysicsBox2DBody* ) body)->setDeleteFlag(true);
}

std::shared_ptr<Physics2DBody> PhysicsBox2DWorld::findBody(const std::string& name) {
    if (_bodyMapByName.count(name) != 0) {
        return _bodyMapByName[name];
    }
    
    return nullptr;
}

void PhysicsBox2DWorld::loadBodies(const std::string &plist) {
    auto loader = GB2ShapeCache::sharedGB2ShapeCache();
    loader->addShapesWithFile(plist);
}

void PhysicsBox2DWorld::registerContactListener(Physics2DContactListener* listener) {
    // TODO
    ((Box2DContactListener*)_contactListener)->addListener(listener);
}

void PhysicsBox2DWorld::drawDebug() {
    
}

std::shared_ptr<Physics2DBody> PhysicsBox2DWorld::findBody(b2Body *b2Body) {
    if (_bodyMap.count(b2Body) != 0) {
        return _bodyMap[b2Body];
    }
    
    return nullptr;
}

END_GAME_NS
