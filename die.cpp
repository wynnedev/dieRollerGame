//
// Created by 200458668 on 11/12/2020.
//

#include "die.hpp"
Die::Die() {
    _sides = 6;
}
Die::Die(int sides) : _sides(sides) {
}
void Die::RollDie() {
    _value = rand() % _sides + 1;
}
void Die::SetSides(int sides) {
    _sides = sides;
}
void Die::ShowDie(std::ostream &os) const {
    os << this->_value << std::endl;
}
int Die::GetValue() const {
    return _value;
}
