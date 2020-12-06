#include <iostream>
#include "UnitedStates.h"
#include "AttackingQueue.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player(){};
        Player(State *state);
        void attack(string toAttack); // Attack an Adjacent State
        void reinforce(); // Increase army size
        void defend(); // Boost defenses
        int getArmySize();
        void printAdjStates();
        bool getAlive();
    private:
        State* playerState;
        AttackingQueue attackers;
        bool isAlive = true;
        bool isAdj(string name);
};

#endif