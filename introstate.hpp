//
// Created by 200458668 on 11/14/2020.
//

#ifndef DIEROLLERGAME_INTROSTATE_HPP
#define DIEROLLERGAME_INTROSTATE_HPP

#include "state.hpp"
#include "game.hpp"

class IntroState : public State {
public:
    IntroState();
    explicit IntroState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
};


#endif
