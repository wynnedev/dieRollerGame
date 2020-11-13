#include <iostream>
#include <ctime>
#include "die.hpp"
#include "dice.hpp"
int main() {
    std::cout << "Program Started" << std::endl;
    srand((unsigned) time(0));
    Die *die = new Die(10);

    Dice *dice = new Dice(2, 6);
    dice->RollDice();
    dice->ShowDice(std::cout);

    std::cout << "Program Ended" << std::endl;
    return 0;
}
