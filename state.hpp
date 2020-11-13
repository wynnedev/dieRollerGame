//
// Created by 200458668 on 11/12/2020.
//

#ifndef DIEROLLERGAME_STATE_HPP
#define DIEROLLERGAME_STATE_HPP


class State {
public:
    virtual ~State() {}
    virtual void handleInput(Game& game, Input input) {};
    virtual void update(Game& game);
};


#endif//DIEROLLERGAME_STATE_HPP
