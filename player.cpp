//
// Created by 200458668 on 11/15/2020.
//

#include "player.hpp"
void Player::RollDice() {
    this->_dice->RollDice();
    std::cout << _name << " rolls his dice \n";
    this->_dice->ShowDice(std::cout);
}
void Player::SetScore() {
    ++_score;
}

int Player::GetDice() const{
    return _dice->GetTotal();
}
void Player::SetDice(Dice *dice) {
    _dice = dice;
}
void Player::SetName(std::string name) {
    _name = name;
}
int Player::GetScore() const {
    return _score;
}
std::string Player::GetName() const {
    return _name;
}
Player::~Player() {
    delete _dice;
}
bool Player::operator>(const Player &player) const {
    return this->_score > player._score;
}

bool Player::operator==(const Player& player) const{
    return this->_score == player._score;
}

bool Player::operator<(const Player &player) const {
    return this->_score < player._score;
}

