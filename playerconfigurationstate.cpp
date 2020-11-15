//
// Created by 200458668 on 11/15/2020.
//

#include "playerconfigurationstate.hpp"
#include "diceconfigurationstate.hpp"
PlayerConfigurationState::PlayerConfigurationState(GameDataRef data) : _data(data){
    _data->_playerConfig = PlayerConfig::PLAYER_INVALID;
}

void PlayerConfigurationState::Init(){
    std::cout << "Player Configuration \n";
    this->_data->p1 = Player();
    this->_data->p2 = Player();
}

void PlayerConfigurationState::HandleInput() {

    while(_data->_playerConfig == PlayerConfig::PLAYER_INVALID) {
        std::cout << "Select Player Configuration: \n"
                  << "(1) Player vs. CPU \n"
                  << "(2) Player vs. Player \n";

        std::cin >> this->_data->input;

        if(this->_data->input == "1"){
            std::cout << "Player 1 vs. CPU Selected \n";
            this->_data->_playerConfig = PlayerConfig::CPU;
            this->_data->p1.SetName("Player 1");
            this->_data->p2.SetName("Play CPU");
        }

        else if (this->_data->input == "2"){
            std::cout << "Player vs Player Selected \n";
            this->_data->_playerConfig = PlayerConfig::PLAYER2;
            this->_data->p1.SetName("Player 1");
            this->_data->p2.SetName("Player 2");
        }

        else{
            std::cerr << "Invalid Selection \n";
        }
    }
}
void PlayerConfigurationState::Update() {
    this->_data->machine.AddState(StateRef(new DiceConfigurationState(_data)));
}
