//
// Created by 200458668 on 11/15/2020.
//

#ifndef DIEROLLERGAME_PLAYERCONFIGURATIONSTATE_HPP
#define DIEROLLERGAME_PLAYERCONFIGURATIONSTATE_HPP

#include "game.hpp"

class PlayerConfigurationState : public State{
public:
    PlayerConfigurationState() = default;
    explicit PlayerConfigurationState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
};


#endif//DIEROLLERGAME_PLAYERCONFIGURATIONSTATE_HPP
