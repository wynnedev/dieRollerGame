//
// Created by 200458668 on 11/15/2020.
//

#ifndef DIEROLLERGAME_DICECONFIGURATIONSTATE_HPP
#define DIEROLLERGAME_DICECONFIGURATIONSTATE_HPP

#include "game.hpp"

class DiceConfigurationState : public State{
public:
    DiceConfigurationState() = default;
    explicit DiceConfigurationState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
};


#endif//DIEROLLERGAME_DICECONFIGURATIONSTATE_HPP
