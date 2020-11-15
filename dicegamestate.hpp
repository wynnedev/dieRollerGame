//
// Created by 200458668 on 11/15/2020.
//

#ifndef DIEROLLERGAME_DICEGAMESTATE_HPP
#define DIEROLLERGAME_DICEGAMESTATE_HPP

#include "game.hpp"

class DiceGameState : public State{
public:
    DiceGameState() = default;
    explicit DiceGameState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
};


#endif//DIEROLLERGAME_DICEGAMESTATE_HPP
