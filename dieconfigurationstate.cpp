//
// Created by 200458668 on 11/15/2020.
//

#include "dieconfigurationstate.hpp"
#include "dicegamestate.hpp"
#include "mainmenustate.hpp"
#include "randomgeneratorstate.hpp"
#include <stdexcept>

DieConfigurationState::DieConfigurationState(GameDataRef data) : _data(data) {
    this->_data->_dieConfig = DieConfig::DIE_INVALID;
}

void DieConfigurationState::Init(){
    std::cout << "Die Configuration \n";
}

void DieConfigurationState::HandleInput() {
    while(_data->_dieConfig == DieConfig::DIE_INVALID) {
        std::cout << "Select Number of Sides: \n"
                  << "(6) D6 \n"
                  << "(10) D10 \n"
                  << "(20) D20 \n";

        std::cin >> this->_data->input;

        if(this->_data->input == "6"){
            std::cout << "D6 Selected \n";
            this->_data->_dieConfig = DieConfig::SIX;
        }

        else if (this->_data->input == "10"){
            std::cout << "D10 Selected \n";
            this->_data->_dieConfig = DieConfig::TEN;
        }

        else if (this->_data->input == "20"){
            std::cout << "D20 Die Selected \n";
            this->_data->_dieConfig = DieConfig::TWENTY;
        }

        else{
            std::cerr << "Invalid Selection \n";
        }
    }
}

void DieConfigurationState::Update(){
    if(this->_data->_gameConfig == GameConfig::DICE) {
        this->_data->machine.AddState(StateRef(new DiceGameState(_data)));
    }

    else if(this->_data->_gameConfig == GameConfig::RANDOM){
        this->_data->machine.AddState(StateRef(new RandomGeneratorState(_data)));
    }

    else{
        this->_data->machine.AddState(StateRef(new MainMenuState(_data)));
        std::cerr << "Invalid State";
    }
}

