#include <iostream>
#include "UnitedStates.h"
#include "Player.h"

using namespace std;

int main() {

    cout << "Welcome to Civil War Simulator!" << endl;

    UnitedStates US = UnitedStates("stateData.txt");

    string state;
    cout << "Enter the state you wish to play as: " << endl;
    getline(cin, state);
    while (US.findState(state) == nullptr) {
        cout << "Not a valid state. Please try again: " << endl;
        getline(cin, state);
    }
    Player player = Player(US.findState(state));
    // US.printStates();

    string actions = "Type \'a\' to launch an attack.\n"
                        "Type \'d\' to defend an incoming attack.\n"
                        "Type \'r\' to reinforce army size for attack or defense.\n"
                        "Type \'s\' to review a list of adjacent states.\n"
                        "Type \'q\' to quit the game at any time.";


    int round = 1;

    while (player.getAlive() && !player.getWon()) {

        cout << '\n' << "Round " << round << endl;
        cout << "Army Size: " << player.getArmySize() << endl;
        cout << actions << endl;

        char action;
        cin >> action;
        cin.clear();
        cin.ignore();

        switch(action) {
            case 'a':
            {
                string attackOption;
                cout << "Who would you like to attack? (Type \'s\' for a reminder of adjacent states):" << endl;
                getline(cin, attackOption);
                cin.clear();
                cin.ignore();
                while (attackOption == "s" || !player.isAdj(attackOption)) {
                    if (attackOption == "s") {
                        player.printAdjStates();
                    } else {
                        cout << "State not recognized. Try again." << endl;
                    }
                    cout << "Who would you like to attack? (Type \'s\' for a reminder of adjacent states):" << endl;
                    getline(cin, attackOption);
                    cin.clear();
                    cin.ignore();
                }
                player.attack(attackOption);
                round++;
                break;
            }
            case 'd':
            {
                player.defend();
                round++;
                break;
            }
            case 'r':
            {
                player.reinforce();
                round++;
                break;
            }
            case 's':
            {
                player.printAdjStates();
                break;
            }
            case 'q':
            {
                return 0;
            }
        }

        player.underAttack();
        // player.printAttackingQueue();
        player.checkWin();

    }

    if (player.getWon()) {
        cout << "Congratulations! You won the 2020 Civil War!" << endl;
    }

    return 0;

}