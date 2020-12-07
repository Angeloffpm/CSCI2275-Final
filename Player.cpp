#include <iostream>
#include <random>
#include "Player.h"
#include "UnitedStates.h"

using namespace std;

// ==============
// Public Methods
// ==============

Player::Player(State *state) {
    playerState = state;
}

bool Player::attack(string toAttack) {
    if (isAdj(toAttack)) {
        if (findAdjState(toAttack)->defeated) {
            cout << "State already defeated" << endl;
            return false;
        } else {
            int attackerValue = rand() % playerState->armySize;
            int defenderValue = rand() % findAdjState(toAttack)->armySize;
            if (attackerValue > defenderValue) { // Victory
                cout << "Your army wont the attack!" << endl;
                conquere(findAdjState(toAttack));
            } else { // Defeat
                cout << "Your army lost the attack!" << endl;
                defeatPenalty(defenderValue);
            }
            return true;
        }
    } else {
        cout << "State not adjacent." << endl;
        return false;
    }
}

void Player::reinforce() { // Increases army size from 0% to 100%;
    int increase = rand() % playerState->armySize;
    playerState->armySize += increase;
    cout << "Army capacity has been increased " << increase << "!" << endl;
}

void Player::defend() { 
    defending = true;
}

void Player::underAttack() {

    int randomAttack = ((double) rand() / (RAND_MAX));
    if (randomAttack >= attackChance) {
        State *attackingState = attackers.dequeue();
        if (attackingState == nullptr) {
            cout << "No states are ready to attack you yet." << endl;
            return;
        }
        int defenseMultiper = 1;
        if (defending) {
            defenseMultiper = 4;
        }

    } else {
        cout << "No adjacent states attacked you this round." << endl;
    }

}

void Player::printAdjStates() {
    cout << "Adjacent States:" << endl;
    for (int i = 0; i < playerState->adjStates.size(); i++) {
        cout << playerState->adjStates[i]->name << " | Army Size: " << playerState->adjStates[i]->armySize << endl;
    }
}

void Player::printAttackingQueue() { // Chance to add a random state to the attackers, then prints queue.

    if (((double) rand() / (RAND_MAX)) > 0.5) {
        State *randomState = playerState->adjStates[rand() % playerState->adjStates.size()];
        if (!randomState->defeated) {
            attackers.enqueue(randomState);
        }
    }

    if (attackers.isEmpty()) {
        cout << "No adjacent states are planning an attack on you." << endl;
    } else {
        attackers.printQueue();
    }
}

void Player::checkWin() {
    if (!playerState->adjStates.size() == 47) {
        return;
    } else {
        for (int i = 0; i < playerState->adjStates.size(); i++) {
            if (!playerState->adjStates[i]->defeated) {
                return;
            }
        }
    }
    won = true;
}

int Player::getArmySize() {
    return playerState->armySize;
}

bool Player::getAlive() {
    return isAlive;
}

bool Player::getWon() {
    return won;
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

State* Player::findAdjState(string name) {
    for (int i = 0; i < playerState->adjStates.size(); i++) {
        if (playerState->adjStates[i]->name == name) {
            return playerState->adjStates[i];
        }
    }
    return nullptr;
}

void Player::defeatPenalty(int loss) {
    playerState->armySize -= loss;
    cout << "Your army lost " << loss << " troops." << endl;
    if (playerState->armySize < 100000) { // If army falls below 100,000, you lose.
        cout << "Your army fell below 100,000 troops. Game over." << endl;
        isAlive = false;
    }
}

void Player::conquere(State *toConquere) {
    cout << "You conquered " << toConquere->name << "! You gain their land and their army of " << toConquere->armySize << "." << endl;
    for (int i = 0; i < toConquere->adjStates.size(); i++) {
        if (!isAdj(toConquere->adjStates[i]->name) && toConquere->adjStates[i]->name != playerState->name) {
            playerState->adjStates.push_back(toConquere->adjStates[i]);
        }
    }
    playerState->armySize += toConquere->armySize;
    toConquere->armySize = 0;
    toConquere->defeated = true;
}