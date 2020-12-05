#include <iostream>
#include <vector>

using namespace std;

struct State {
    State();
    string name;
    int armySize;
    vector<State> adjStates;
};

class UnitedStates {
    public:
        UnitedStates(string data); // Constructor
        State findState(string name);
        void simulateRound(); // States randomly attack eachother.
    private:
        void buildMap();
        vector<State> states;
};