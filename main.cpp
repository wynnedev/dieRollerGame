#include "game.hpp"
#include "introstate.hpp"
#include <ctime>
#include <iostream>


int main() {
    srand((unsigned) time(0));

    Game game;
    game.Run();

    return 0;
}
