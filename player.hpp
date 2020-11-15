//
// Created by 200458668 on 11/15/2020.
//

#ifndef DIEROLLERGAME_PLAYER_HPP
#define DIEROLLERGAME_PLAYER_HPP

#include <iostream>
#include "dice.hpp"

class Player{
public:
    Player() = default;
    ~Player();
    Player(std::string& name) : _name(name), _score(0){}
    void SetDice(Dice* dice);
    void SetName(std::string name);
    void RollDice();
    int GetDice() const;
    void SetScore();
    int GetScore() const;
    std::string GetName() const;
    bool operator>(const Player& player) const;
    bool operator==(const Player& player) const;
    bool operator<(const Player& player) const;
private:
    std::string _name;
    Dice* _dice;
    int _score;
};


#endif//DIEROLLERGAME_PLAYER_HPP
