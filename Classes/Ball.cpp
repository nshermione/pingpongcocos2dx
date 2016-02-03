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

bool Ball::init(cocos2d::Sprite *sprite) {
    reset();
    setSprite(sprite);
    
    // schedulers
    sprite->schedule(CC_CALLBACK_1(Ball::controlVelocity, this), 0.02f, "velocityController");
    
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
    auto size = sprite->getContentSize();
    auto physicsBody = PhysicsBody::createCircle(size.width/2,
                                                 PhysicsMaterial(0.1f, 1.0f, 0.0f));
    
    //set the body isn't affected by the physics world's gravitational force
    physicsBody->setGravityEnable(false);
    physicsBody->setCollisionBitmask(0x0001);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    
    //set initial velocity of physicsBody
    physicsBody->setVelocity(Vec2(cocos2d::random(-100,100),
                                  cocos2d::random(-100,100)));
    sprite->setPhysicsBody(physicsBody);
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
    auto sprite = getSprite();
    if (sprite->getPhysicsBody()) {
        auto velocity = sprite->getPhysicsBody()->getVelocity();
        velocity.normalize();
        velocity.scale(vel);
        sprite->getPhysicsBody()->setVelocity(velocity);
        
        //update trail
        if (currentTrail != NULL) {
            auto angle = atan2(velocity.y, velocity.x) * 180 / M_PI + 180;
            currentTrail->setAngle(angle);
        }
    }
}

void Ball::setTrail(cocos2d::ParticleSystemQuad* trail) {

    if (currentTrail != NULL && trail != currentTrail) {
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
    if (totalTime > 0 && totalTime < 30) {
        speedByTime = 100;
    } else if (totalTime < 60) {
        speedByTime = 150;
    } else if (totalTime < 90) {
        speedByTime = 200;
    } else {
        speedByTime = 250;
    }
    
    totalSpeed = speedByTime + speedVariant;
    setVelocity(totalSpeed);
    
    // Update trail by speed
    if (totalSpeed > 120 && totalSpeed < 200) {
        setTrail(trail1);
    } else if (totalSpeed >= 200) {
        setTrail(trail2);
    }
}