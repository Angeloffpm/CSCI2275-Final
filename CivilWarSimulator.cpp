#include <iostream>
#include "UnitedStates.h"
#include "Player.h"

using namespace std;

int main() {

    cout << "Welcome to Civil War Simulator!" << endl;

    UnitedStates US = UnitedStates("stateData.txt");

    string state;
    cout << "Enter the state you wish to play as: " << endl;
    cin >> state;
    while (US.findState(state) == nullptr) {
        cout << "Not a valid state. Please try again: " << endl;
        cin >> state;
    }
    Player player = Player(US.findState(state));

    string actions = "Type \'attack\' to launch an attack.\n"
                        "Type \'defend\' to bolster an incoming attack.\n"
                        "Type \'reinforce\' to increase army size for attack or defense.\n"
                        "Type \'neighbors\' to review a list of adjacent states.\n";
    cout << actions << endl;

    int round = 1;
    while(player.getAlive()) {
        cout << "Round " << round << endl;
        cout << "Choose an action. (Type \'remind\' for a reminder of actions)" << endl;


    }



}