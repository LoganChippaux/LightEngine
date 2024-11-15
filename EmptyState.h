// EmptyState.h
#pragma once
#include "State.h"
#include "Gun.h"

class Gun;

class EmptyState : public State {
public:
    void Start(Gun* gun) override {
        std::cout << "Pas de balles restantes !" << std::endl;
    }

    void Update(Gun* gun, float deltaTime) override {
    }
};
