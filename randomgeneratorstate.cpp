//
// Created by 200458668 on 11/14/2020.
//

#include "randomgeneratorstate.hpp"
#include "dice.hpp"
#include "mainmenustate.hpp"

RandomGeneratorState::RandomGeneratorState(GameDataRef data) : _data(data) {
}
void RandomGeneratorState::Init() {
    this->_data->nextRound = true;
    std::cout << "This Program Will Generate a Random Number:" << std::endl;
    system("pause");
}
void RandomGeneratorState::HandleInput(){

    Dice* dice = new Dice(this->_data->_diceConfig, this->_data->_dieConfig);
    std::cout << "(" << this->_data->_diceConfig << ")" << this->_data->_dieConfig << " sided die will be rolled \n";
    dice->RollDice();
    dice->ShowDice(std::cout);

    std::cout << "Press Y to Roll Again \n";
    std::cin >> _data->input;
}
void RandomGeneratorState::Update() {
    if(_data->input == "Y"){
        this->_data->machine.AddState(StateRef(new RandomGeneratorState(_data)));
    }

    else{
        this->_data->machine.AddState(StateRef(new MainMenuState(_data)));
    }
}
