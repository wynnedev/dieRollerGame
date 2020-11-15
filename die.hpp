//
// Created by 200458668 on 11/12/2020.
//

#ifndef DIEROLLERGAME_DIE_HPP
#define DIEROLLERGAME_DIE_HPP
#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>

class Die {
public:
    Die();
    explicit Die(int sides);
    void RollDie();
    void ShowDie(std::ostream& os) const;
    void SetSides(int sides);
    int GetValue() const;
    int operator+(const Die& die) const;

private:
    int _sides;
    int _value{};
};


#endif//DIEROLLERGAME_DIE_HPP
