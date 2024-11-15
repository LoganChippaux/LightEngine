// ReloadingState.h
#pragma once
#include "State.h"
#include "Gun.h"

class Gun;

class ReloadingState : public State {
public:
    void Start(Gun* gun) override {
        gun->Reload();
    }

    void Update(Gun* gun, float deltaTime) override {
    }
};
