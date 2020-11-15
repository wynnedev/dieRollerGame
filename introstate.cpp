//
// Created by 200458668 on 11/14/2020.
//

#include "introstate.hpp"
#include "mainmenustate.hpp"

IntroState::IntroState() {
}

IntroState::IntroState(GameDataRef data) : _data(data){
}
void IntroState::Init() {
    //display intro message
    std::cout << "Welcome to the Dice Roller" << std::endl;
}
void IntroState::HandleInput() {
    //get user input
    system("pause");
}
void IntroState::Update() {
    //move to main menu
    this->_data->machine.AddState(StateRef(new MainMenuState(_data)));
}
