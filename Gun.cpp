// Gun.cpp
#include "Gun.h"

Gun::Gun(int capacity, int ammo, float reloadTime)
    : mCapacity(capacity), mAmmo(ammo), mReloadTime(reloadTime) {
    mStates[(int)GunState::Idle] = new IdleState();
    mStates[(int)GunState::Shooting] = new ShootingState();
    mStates[(int)GunState::Reloading] = new ReloadingState();
    mStates[(int)GunState::Empty] = new EmptyState();
    SetState(GunState::Idle); 
}

Gun::~Gun() {
    for (int i = 0; i < 4; ++i) {
        delete mStates[i];
    }
}

void Gun::SetState(GunState newState) {
    mCurrentState = mStates[(int)newState];
    mCurrentState->Start(this);
}

void Gun::Update(float deltaTime) {
    if (mCurrentState) {
        mCurrentState->Update(this, deltaTime);
    }
}

void Gun::Shoot() {
    if (mAmmo > 0) {
        std::cout << "BAAAAAAM" << std::endl;
        mAmmo--;
        if (mAmmo == 0) {
            SetState(GunState::Empty);
        }
    }
    else {
        std::cout << "Pas de balles restantes, rechargez !" << std::endl;
    }
}

void Gun::Reload() {
    mAmmo = mCapacity;
    std::cout << "Je recharge..." << std::endl;
}
