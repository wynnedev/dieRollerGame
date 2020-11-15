//
// Created by 200458668 on 11/14/2020.
//

#include "mainmenustate.hpp"
#include "diceconfigurationstate.hpp"
#include "playerconfigurationstate.hpp"
#include "randomgeneratorstate.hpp"

MainMenuState::MainMenuState() {
}
MainMenuState::MainMenuState(GameDataRef data) : _data(data) {
}
void MainMenuState::Init() {
    std::cout << "Welcome to Dice Roller v1.0" << std::endl;
    std::cout << "Please select an option" << std::endl
    << "(1) Play Game\n"
    << "(2) Generate Random Number\n"
    << "(3) Quit Game\n"
    << std::endl;
}

void MainMenuState::HandleInput() {
    std::cin >> _data->input;

    if(_data->input == "1"){
        _data->_gameConfig = GameConfig::DICE;
    }

    else if(_data->input == "2"){
        _data->_gameConfig = GameConfig::RANDOM;
    }

    else if(_data->input =="3"){
        _data->_gameConfig = GameConfig::QUIT;
    }

    else{
        _data->_gameConfig = GameConfig::INVALID;
    }
}
void MainMenuState::Update() {
    switch(_data->_gameConfig){
        case GameConfig::INVALID:
            std::cout << "Invalid Game Type Selected! \n";
            break;

        case GameConfig::DICE:
            this->_data->machine.AddState(StateRef(new PlayerConfigurationState(_data)));
            break;

        case GameConfig::RANDOM:
            this->_data->machine.AddState(StateRef(new DiceConfigurationState(_data)));
            break;

        case GameConfig::QUIT:
            std::cout << "Thank You for Playing Dice Roller v1.0 \n";
            _data->playGame = false;
            break;

        default:
            std::cout << "Invalid Game Type Selected! \n";
            break;
    }
}
