//
//  PhysicsBox2D.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/11/16.
//
//

#include "PhysicsBox2D.h"

START_GAME_NS

// PhysicsBox2DBody

PhysicsBox2DBody::PhysicsBox2DBody() {
    
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
    _body->SetTransform(b2Vec2(vel.x, vel.y), transform.q.GetAngle());
}

void PhysicsBox2DBody::movePosition(const cocos2d::Vec2 &vel) {
    auto transform = _body->GetTransform();
    auto newPos = b2Vec2(transform.p.x + vel.x/BOX2D_PTM_RATIO,
                         transform.p.y + vel.y/BOX2D_PTM_RATIO);
    _body->SetTransform(newPos, transform.q.GetAngle());
}

cocos2d::Vec2 PhysicsBox2DBody::getPosition() {
    auto pos = _body->GetTransform().p;
    return cocos2d::Vec2(pos.x, pos.y);
}

bool PhysicsBox2DBody::isSupportCCD() {
    return true;
}

void PhysicsBox2DBody::enableCCD() {
    _body->SetBullet(true);
}

// PhysicsBox2DWorld

void PhysicsBox2DWorld::init(cocos2d::Scene *scene, float gravityX, float gravityY) {
    Physics2DWorld::init(scene, gravityX, gravityY);
    
    b2Vec2 gravity;
    gravity.Set(gravityX, gravityY);
    
    // create a world object, which will hold and simulate the rigid bodies.
    _world = new b2World(gravity);
    
    // schedule physics main loop
    scene->schedule(CC_CALLBACK_1(PhysicsBox2DWorld::update, this), 0.016f, "updatePhysicsBox2dWorld");
}

void PhysicsBox2DWorld::update(float dt) {
    _world->Step(dt, 10, 10);
    for(b2Body *b = _world->GetBodyList(); b; b=b->GetNext()) {
        if (b->GetUserData() != NULL) {
            cocos2d::Sprite *sprite = (cocos2d::Sprite *)b->GetUserData();
            auto pos = b->GetPosition();
            sprite->setPosition(pos.x * BOX2D_PTM_RATIO, pos.y * BOX2D_PTM_RATIO);
            sprite->setRotation(-1 * CC_RADIANS_TO_DEGREES(b->GetAngle()));
        }
    }
}


Physics2DBody* PhysicsBox2DWorld::addBody(cocos2d::Sprite* sprite, const std::string &bodyName) {
    auto loader = GB2ShapeCache::sharedGB2ShapeCache();
    auto pos = sprite->getPosition();
    b2Body *body;
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(pos.x / BOX2D_PTM_RATIO, pos.y / BOX2D_PTM_RATIO);
    bodyDef.userData = sprite;
    body = _world->CreateBody(&bodyDef);
    loader->addFixturesToBody(body, bodyName);
    
    PhysicsBox2DBody *pBody = new PhysicsBox2DBody();
    pBody->setBody(body);
    pBody->setSprite(sprite);
    
    return pBody;
}

Physics2DBody* PhysicsBox2DWorld::addBodyBox(cocos2d::Sprite* sprite,
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
    
    PhysicsBox2DBody *pBody = new PhysicsBox2DBody();
    pBody->setBody(body);
    pBody->setSprite(sprite);
    
    return pBody;
}

Physics2DBody* PhysicsBox2DWorld::addBodyCircle(cocos2d::Sprite* sprite,
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
    
    PhysicsBox2DBody *pBody = new PhysicsBox2DBody();
    pBody->setBody(body);
    pBody->setSprite(sprite);
    
    return pBody;
}

void PhysicsBox2DWorld::loadBodies(const std::string &plist) {
    auto loader = GB2ShapeCache::sharedGB2ShapeCache();
    loader->addShapesWithFile(plist);
}

void PhysicsBox2DWorld::registerContactListener(Physics2DContactListener listener) {
    // TODO
}

void PhysicsBox2DWorld::drawDebug() {
    
}

END_GAME_NS
