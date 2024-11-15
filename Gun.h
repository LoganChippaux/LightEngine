// Gun.h
#pragma once
#include <iostream>
#include "State.h"
#include "IdleState.h"
#include "ShootingState.h"
#include "ReloadingState.h"
#include "EmptyState.h"

class Gun {
public:
    enum class GunState {
        Idle,
        Shooting,
        Reloading,
        Empty
    };

private:
    int mAmmo;
    int mCapacity;
    float mReloadTime;
    State* mCurrentState = nullptr;
    State* mStates[4];

public:
    Gun(int capacity, int ammo, float reloadTime);
    ~Gun();

    void SetState(GunState newState);
    void Update(float deltaTime);
    void Shoot();
    void Reload();
};
