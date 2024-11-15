// ShootingState.h
#pragma once
#include "State.h"
#include "Gun.h"

class Gun;

class ShootingState : public State {
public:
    void Start(Gun* gun) override {
        
    }

    void Update(Gun* gun, float deltaTime) override {
        gun->Shoot(); 
    }
};
