#include <iostream>
#include "Player.h"
#include "UnitedStates.h"

using namespace std;

// ==============
// Public Methods
// ==============

Player::Player(State *state) {
    playerState = state;
}

void Player::attack(string toAttack) {
    if (isAdj(toAttack)) {



    } else {
        cout << "State not adjacent." << endl;
    }
}

void Player::printAdjStates() {
    cout << "Adjacent States:" << endl;
    for (int i = 0; i < playerState->adjStates.size(); i++) {
        cout << playerState->adjStates[i]->name << " | Army Size: " << playerState->adjStates[i]->armySize << endl;
    }
}

bool Player::getAlive() {
    return isAlive;
}

// ==============
// Private Methods
// ==============

bool Player::isAdj(string name) {

    for (int i = 0; i < playerState->adjStates.size(); i++) {
        if (playerState->adjStates[i]->name == name) {
            return true;
        }
    }
    return false;

}