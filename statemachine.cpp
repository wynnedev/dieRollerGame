//
// Created by 200458668 on 11/14/2020.
//

#include "statemachine.hpp"

void StateMachine::AddState(StateRef newState, bool ReplaceCurrentState){
    this->_addState = true;
    this->_replaceState = ReplaceCurrentState;
    this->_newState = std::move(newState);
}
void StateMachine::RemoveState() {
    this->_removeState = true;
}
void StateMachine::ProcessStateChanges() {
    //
    if(this->_removeState && !this->_stateStack.empty()){
        this->_stateStack.pop();

        if(!this->_stateStack.empty()){
            this->_stateStack.top()->Resume();
        }
        this->_removeState = false;
    }

    if(this->_addState){
        if(!this->_stateStack.empty()){
            if(this->_replaceState){
                this->_stateStack.pop();
            }

            else{
                this->_stateStack.top()->Pause();
            }
        }
        this->_stateStack.push(std::move(this->_newState));
        this->_stateStack.top()->Init();
        this->_addState = false;
    }
}
StateRef &StateMachine::GetCurrentState() {
    return this->_stateStack.top();
}
