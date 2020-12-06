#include <iostream>
#include <vector>
#ifndef UNITED_STATES_H
#define UNITED_STATES_H

using namespace std;

struct State {
    State(){};
    State(string toName, int toArmySize) {
        name = toName;
        armySize = toArmySize;
    }
    string name;
    int armySize;
    bool defeated = false;
    vector<State*> adjStates;
};

class UnitedStates {
    public:
        UnitedStates(string data); // Constructor
        void simulateRound(); // States randomly attack eachother.
        void resetGame();
        void printStates();
        State* findState(string name);
    private:
        vector<State*> states;
        void buildMap(string data);
};

#endif