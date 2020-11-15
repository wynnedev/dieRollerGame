//
// Created by 200458668 on 11/15/2020.
//

#include "dicegamestate.hpp"
#include "mainmenustate.hpp"

DiceGameState::DiceGameState(GameDataRef data) : _data(data){
}

void DiceGameState::Init() {
    this->_data->p1.SetDice(new Dice(this->_data->_diceConfig, this->_data->_dieConfig));
    this->_data->p2.SetDice(new Dice(this->_data->_diceConfig, this->_data->_dieConfig));
    this->_data->nextRound = true;

    if(currentRound == 0) {
        std::cout << " Let The Games Begin!!! \n";
        system("pause");
    }
}

void DiceGameState::HandleInput() {
    ++currentRound;

    std::cout << "\n--------------------------------------------------------------------------------\n";
    std::cout << "                               Round " << currentRound << "\n";
    std::cout << "--------------------------------------------------------------------------------\n";

    std::cout << this->_data->p1.GetName() << " will roll " << "(" << this->_data->_diceConfig << ")" << this->_data->_dieConfig << std::endl << std::endl;
    this->_data->p1.RollDice();
    std::cout << this->_data->p2.GetName() << " will roll " << "(" << this->_data->_diceConfig << ")" << this->_data->_dieConfig << std::endl << std::endl;
    this->_data->p2.RollDice();

    if(this->_data->p1.GetDice() > this->_data->p2.GetDice()){
        this->_data->p1.SetScore();
        std::cout << this->_data->p1.GetName() <<" wins the round \n";
    }

    else if(this->_data->p2.GetDice() > this->_data->p1.GetDice()){
        this->_data->p2.SetScore();
        std::cout << this->_data->p2.GetName() <<" wins the round \n";
    }

    else{
        std::cout << "The Round is a Tie \n";
    }

    std::cout << "Round: " << currentRound << std::endl
    << this->_data->p1.GetName() << " :: " << this->_data->p1.GetScore() << std::endl
    << this->_data->p2.GetName() << " :: " << this->_data->p2.GetScore() << std::endl;

    std::cout << "Would You Like To Play Another Round? (Y/N)\n";
    std::cin >> this->_data->input;

    if(this->_data->input == "N"){
        if(this->_data->p1.GetScore() > this->_data->p2.GetScore()){
            std::cout << this->_data->p1.GetName() << " has won the match \n";
        }

        else if(this->_data->p1.GetScore() < this->_data->p2.GetScore()){
            std::cout << this->_data->p2.GetName() << " has won the match \n";
        }

        else{
            std::cout << "The Game is a Tie \n";
        }
        std::cout << "Thank you for playing \n";
        std::cout << "\n--------------------------------------------------------------------------------\n";
        std::cout << "                               Game Over \n";
        std::cout << "--------------------------------------------------------------------------------\n";
        this->_data->nextRound = false;
    }
}

void DiceGameState::Update() {
    if(this->_data->nextRound){
        this->_data->machine.AddState(StateRef(new DiceGameState(_data)));
    }

    else {
        currentRound = 0;
        this->_data->machine.AddState(StateRef(new MainMenuState(_data)));
    }
}
