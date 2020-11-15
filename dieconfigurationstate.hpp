//
// Created by 200458668 on 11/15/2020.
//

#ifndef DIEROLLERGAME_DIECONFIGURATIONSTATE_HPP
#define DIEROLLERGAME_DIECONFIGURATIONSTATE_HPP

#include "game.hpp"

class DieConfigurationState : public State {
public:
    DieConfigurationState() = default;
    explicit DieConfigurationState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
};


#endif//DIEROLLERGAME_DIECONFIGURATIONSTATE_HPP
