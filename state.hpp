//
// Created by 200458668 on 11/12/2020.
//

#ifndef DIEROLLERGAME_STATE_HPP
#define DIEROLLERGAME_STATE_HPP

class State {
public:
    virtual void Init() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;

    virtual void Pause() {}
    virtual void Resume() {}
};



#endif//DIEROLLERGAME_STATE_HPP
