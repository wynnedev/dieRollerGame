//
// Created by 200458668 on 11/12/2020.
//

#ifndef DIEROLLERGAME_DICE_HPP
#define DIEROLLERGAME_DICE_HPP
#include <vector>
#include "die.hpp"
class Dice {
public:
    Dice();
    Dice(int totalDie, int totalSides);
    void RollDice();
    void ShowDice(std::ostream &os) const;

private:
    std::vector<Die> _dice;
    int _total{};
};


#endif//DIEROLLERGAME_DICE_HPP
