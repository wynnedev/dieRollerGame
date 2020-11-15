//
// Created by 200458668 on 11/14/2020.
//

#ifndef DIEROLLERGAME_STATEMACHINE_HPP
#define DIEROLLERGAME_STATEMACHINE_HPP
#include <memory>
#include <stack>
#include "state.hpp"

typedef std::unique_ptr<State> StateRef;

class StateMachine {
public:
    StateMachine()= default;;
    ~StateMachine()= default;

    void AddState(StateRef newState, bool ReplaceCurrentState = true);
    void RemoveState();

    void ProcessStateChanges();
    StateRef& GetCurrentState();

private:
    std::stack<StateRef> _stateStack;
    StateRef _newState;

    bool _removeState, _addState, _replaceState;

};


#endif//DIEROLLERGAME_STATEMACHINE_HPP
