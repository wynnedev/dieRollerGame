//
// Created by 200458668 on 11/14/2020.
//

#ifndef DIEROLLERGAME_MAINMENUSTATE_HPP
#define DIEROLLERGAME_MAINMENUSTATE_HPP

#include "state.hpp"
#include "game.hpp"

class MainMenuState : public State {
public:
    MainMenuState();
    explicit MainMenuState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
};


#endif//DIEROLLERGAME_MAINMENUSTATE_HPP
