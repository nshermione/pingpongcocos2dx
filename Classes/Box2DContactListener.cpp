//
//  Box2DContactListener.cpp
//  pingpong
//
//  Created by Thinh Tran on 2/15/16.
//
//

#include "Box2DContactListener.h"

START_GAME_NS



void Box2DContactListener::BeginContact(b2Contact* contact) {
    _pContact = std::make_shared<PhysicsBox2DContact>(_world, contact);
    for (auto listener : _listeners) {
        _pContact->changeTarget(listener->getTarget());
        if (listener->onContactBegin != nullptr) {
            if (listener->onContactBegin(_pContact)) return;
        }
    }
}

void Box2DContactListener::EndContact(b2Contact* contact) {
    for (auto listener : _listeners) {
        if (listener->onContactEnd != nullptr) {
            if (listener->onContactEnd(_pContact)) return;
        }
    }
}

void Box2DContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
    _pContact = std::make_shared<PhysicsBox2DContact>(_world, contact);
    for (auto listener : _listeners) {
        _pContact->changeTarget(listener->getTarget());
        if (listener->onContactPreSolve != nullptr) {
            if (listener->onContactPreSolve(_pContact)) return;
        }
    }
}

void Box2DContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
    for (auto listener : _listeners) {
        _pContact->changeTarget(listener->getTarget());
        if (listener->onContactPostSolve != nullptr) {
            if (listener->onContactPostSolve(_pContact)) return;
        }
    }
}

END_GAME_NS