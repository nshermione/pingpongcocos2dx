//
//  Ball.cpp
//  pingpong
//
//  Created by Thinh Tran on 1/13/16.
//
//

#include "Ball.h"
#include <math.h>

USING_NS_CC;

std::string Ball::NAME = "ball";


float NORMAL_SPEED = 15;
float FAST_SPEED = 20;
float VERY_FAST_SPEED = 25;
float EXTREMELY_SPEED = 35;

Ball::Ball()
:physicsBody(nullptr)
,currentTrail(nullptr)
,trail1(nullptr)
,trail2(nullptr)
{
    
}

Ball::~Ball() {
    SAFE_DELETE_POINTER(physicsBody);
}

bool Ball::init(cocos2d::Sprite *sprite) {
    reset();
    setSprite(sprite);
    
    // schedulers
    sprite->schedule(CC_CALLBACK_1(Ball::controlVelocity, this), 0.016f, "velocityController");
    
    initShader();
    initParticle();
    initPhysics();
    
    return true;
}

void Ball::reset() {
    totalTime = 0;
    totalSpeed = 0;
    speedVariant = 0;
    speedByTime = 0;
}

void Ball::initPhysics() {
    auto sprite = getSprite();
    auto world = Physics::getWorld2D();
    
    physicsBody = world->addBody(sprite, "ball");
    
    //set the body isn't affected by the physics world's gravitational force
    physicsBody->setDynamic(true);
    physicsBody->setGravity(false);
    physicsBody->setCollisionBitmask(0x0001);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    physicsBody->setGroup(0);
    
    if (physicsBody->isSupportCCD()) {
        physicsBody->enableCCD();
    }
    
    //set initial velocity of physicsBody
    physicsBody->setVelocity(Vec2(cocos2d::random(-NORMAL_SPEED, NORMAL_SPEED),
                                  cocos2d::random(-NORMAL_SPEED/3, NORMAL_SPEED/3)));

}

void Ball::initShader() {
    auto sprite = getSprite();
    GLProgram* prog = new GLProgram();
    prog->initWithFilenames("ball.vs", "ball.fs");
    prog->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_POSITION, GLProgram::VERTEX_ATTRIB_POSITION);
    prog->bindAttribLocation(GLProgram::ATTRIBUTE_NAME_TEX_COORD, GLProgram::VERTEX_ATTRIB_TEX_COORDS);
    prog->link();
    
    prog->updateUniforms();
    prog->use();
    
    
    GLProgramCache::getInstance()->addGLProgram(prog, "ball");
    
    //auto prog1 = GLProgramCache::getInstance()->getGLProgram(GLProgram::SHADER_NAME_POSITION_TEXTURE_ALPHA_TEST_NO_MV);
    sprite->setGLProgram(prog);
    prog->release();
}

void Ball::initParticle() {
    auto sprite = getSprite();
    trail1 = ParticleSystemQuad::create("dust.plist");
    trail2 = ParticleSystemQuad::create("trail.plist");
    
    sprite->addChild(trail1, 10);
    sprite->addChild(trail2, 10);
    
    auto ballSize = sprite->getContentSize();
    trail1->setPosition(ballSize.width/2, ballSize.height/2);
    trail2->setPosition(ballSize.width/2, ballSize.height/2);
    
    trail1->setVisible(false);
    trail2->setVisible(false);
}

void Ball::setVelocity(float vel) {
    if (physicsBody != nullptr) {
        auto velocity = physicsBody->getVelocity();
        velocity.normalize();
        velocity.scale(vel);
        physicsBody->setVelocity(velocity);
        
        //update trail
        if (currentTrail != nullptr) {
            auto angle = atan2(velocity.y, velocity.x) * 180 / M_PI + 180;
            currentTrail->setAngle(angle);
        }
    }
}

void Ball::setTrail(cocos2d::ParticleSystemQuad* trail) {

    if (currentTrail != nullptr && trail != currentTrail) {
        currentTrail->setVisible(false);
    }
    
    if (trail != currentTrail) {
        currentTrail = trail;
        currentTrail->setVisible(true);
    }
}

void Ball::controlVelocity(float dt) {
    totalTime += dt;
    
    // Get speed by time
    if (totalTime > 0 && totalTime < 10) {
        speedByTime = NORMAL_SPEED;
    } else if (totalTime < 20) {
        speedByTime = FAST_SPEED;
    } else if (totalTime < 30) {
        speedByTime = VERY_FAST_SPEED;
    } else {
        speedByTime = EXTREMELY_SPEED;
    }
    
    totalSpeed = speedByTime + speedVariant;
    setVelocity(totalSpeed);
    
    // Update trail by speed
    if (totalSpeed > NORMAL_SPEED && totalSpeed < VERY_FAST_SPEED) {
        setTrail(trail1);
    } else if (totalSpeed >= VERY_FAST_SPEED) {
        setTrail(trail2);
    }
}