#include <iostream>
#include "UnitedStates.h"
#include "AttackingQueue.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    public:
        Player(){};
        Player(State *state);
        bool attack(string toAttack); // Attack an Adjacent State
        void reinforce(); // Increase army size
        void defend(); // Boost defenses
        void underAttack();
        void printAdjStates();
        void printAttackingQueue();
        void checkWin();
        bool isAdj(string name);
        int getArmySize();
        bool getAlive();
        bool getWon();
        AttackingQueue attackers;
    private:
        State* playerState;
        double attackChance = 0.5;
        bool defending = false;
        bool isAlive = true;
        bool won = false;
        State* findAdjState(string name);
        void defeatPenalty(int loss);
        void conquere(State *toConquere);
};

#endif