//
// Created by 200458668 on 11/15/2020.
//

#include "diceconfigurationstate.hpp"
#include "dieconfigurationstate.hpp"
DiceConfigurationState::DiceConfigurationState(GameDataRef data) : _data(data) {
    this->_data->_diceConfig = DiceConfig::DICE_INVALID;
}

void DiceConfigurationState::Init(){
    std::cout << "Dice Configuration \n";
}

void DiceConfigurationState::HandleInput() {
    while(_data->_diceConfig == DiceConfig::DICE_INVALID) {
        std::cout << "Select Number of Dice: \n"
                  << "(1) One \n"
                  << "(2) Two \n"
                  << "(3) Three \n";

        std::cin >> this->_data->input;

        if(this->_data->input == "1"){
            std::cout << "One Die Selected \n";
            this->_data->_diceConfig = DiceConfig::ONE;
        }

        else if (this->_data->input == "2"){
            std::cout << "Two Die Selected \n";
            this->_data->_diceConfig = DiceConfig::TWO;
        }

        else if (this->_data->input == "3"){
            std::cout << "Three Die Selected \n";
            this->_data->_diceConfig = DiceConfig::THREE;
        }

        else{
            std::cerr << "Invalid Selection \n";
        }
    }
}

void DiceConfigurationState::Update(){
    this->_data->machine.AddState(StateRef(new DieConfigurationState(_data)));
}
