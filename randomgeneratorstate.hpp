//
// Created by 200458668 on 11/14/2020.
//

#ifndef DIEROLLERGAME_RANDOMGENERATORSTATE_HPP
#define DIEROLLERGAME_RANDOMGENERATORSTATE_HPP

#include "game.hpp"
#include "state.hpp"

class RandomGeneratorState : public State {
public:
public:
    RandomGeneratorState() = default;
    explicit RandomGeneratorState(GameDataRef data);
    void Init() override;
    void HandleInput() override;
    void Update() override;

private:
    GameDataRef _data;
    int _totalDie;
    int _totalSides;
};


#endif//DIEROLLERGAME_RANDOMGENERATORSTATE_HPP
