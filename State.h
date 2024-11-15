// State.h
#pragma once

class Gun;

class State {
public:
    virtual ~State() = default;
    virtual void Start(Gun* gun) = 0;
    virtual void Update(Gun* gun, float deltaTime) = 0;
};
