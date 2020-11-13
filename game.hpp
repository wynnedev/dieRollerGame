//
// Created by 200458668 on 11/12/2020.
//

#ifndef DIEROLLERGAME_GAME_HPP
#define DIEROLLERGAME_GAME_HPP

enum GAME_TYPE {DIE_GAME, RANDOM_ROLL};

class Game {
public:
    Game();
    Game(GAME_TYPE gameType);

private:
    int _playerScore;
    int _opponentScore;
    int _roundNumber;
    Dice dice;

};


#endif//DIEROLLERGAME_GAME_HPP
