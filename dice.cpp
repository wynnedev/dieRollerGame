//
// Created by 200458668 on 11/12/2020.
//

#include "dice.hpp"
Dice::Dice() : _total(0) {
    _dice = std::vector<Die>();
}
Dice::Dice(int totalDie, int sides) : _total(0){
    while(totalDie--){
        Die newDie = Die(sides);
        _dice.push_back(newDie);
    }
}

void Dice::RollDice() {
    _total = 0;
    for( auto& die : _dice){
        die.RollDie();
        _total += die.GetValue();
    }
}

void Dice::ShowDice(std::ostream &os) const {
    for(auto& die : _dice){
        die.ShowDie(os);
    }

    std::cout << "Total: " << _total << "\n\n";
}
bool Dice::operator>(const Dice &dice) const {
    return this->_total > dice._total;
}
bool Dice::operator==(const Dice &dice) const {
    return this->_total == dice._total;
}
int Dice::GetTotal() const {
    return _total;
}
