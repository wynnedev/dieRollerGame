//
// Created by 200458668 on 11/12/2020.
//

#include "game.hpp"
#include "introstate.hpp"

Game::Game() {
    _data->machine.AddState(StateRef(new IntroState(this->_data)));
    _data->playGame = true;
}

void Game::Run() {
    std::cout << "Run()" << std::endl;

    while(this->_data->playGame){
        //Process State Change
        this->_data->machine.ProcessStateChanges();
        this->_data->machine.GetCurrentState()->HandleInput();
        this->_data->machine.GetCurrentState()->Update();
    }
    this->_data->machine.RemoveState();
}

