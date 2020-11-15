//
// Created by 200458668 on 11/12/2020.
//

#ifndef DIEROLLERGAME_GAME_HPP
#define DIEROLLERGAME_GAME_HPP

#include <memory>
#include <string>
#include <iostream>
#include "statemachine.hpp"
#include "dice.hpp"
#include "player.hpp"

enum class PlayerConfig {PLAYER2, CPU, PLAYER_INVALID};
enum class GameConfig{ DICE, RANDOM, INVALID, QUIT };
enum DieConfig{ SIX = 6, TEN = 10, TWENTY =20, DIE_INVALID = -1};
enum DiceConfig{ ONE = 1, TWO = 2, THREE = 3, DICE_INVALID = -1};

static int currentRound = 0;

struct {
    StateMachine machine;
    std::string input;
    int _totalSides;
    PlayerConfig _playerConfig;
    GameConfig _gameConfig;
    DieConfig _dieConfig;
    DiceConfig _diceConfig;
    Player p1;
    Player p2;
    bool nextRound;
    bool playGame;
} typedef GameData;

typedef std::shared_ptr<GameData> GameDataRef;

class Game {
public:
    Game();
    void Run();
private:
    GameDataRef _data = std::make_shared<GameData>();
};


#endif
