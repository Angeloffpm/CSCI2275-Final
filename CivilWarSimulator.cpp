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
    // US.printStates();

    string actions = "Type \'a\' to launch an attack.\n"
                        "Type \'d\' to defend an incoming attack.\n"
                        "Type \'r\' to reinforce army size for attack or defense.\n"
                        "Type \'s\' to review a list of adjacent states.\n"
                        "Type \'q\' to quit the game at any time.";


    int round = 1;
    while(player.getAlive() && !player.getWon()) { // Run Game until Player Dies or Wins
    
        cout << "Round " << round << endl;
        cout << "Army Size: " << player.getArmySize() << endl;
        cout << actions << endl;

        char action;
        bool exit = false;
        while (cin >> action) { // Loop until an action that counts as a 'round' is taken.

            cin.clear();
            cin.ignore();
            switch(action) {
                case 'a': // Attack
                {
                    string attackOption;
                    cout << "Who would you like to attack? (Type \'s\' to review a list of adjacent states.): ";
                    cin >> attackOption;
                    cin.clear();
                    cin.ignore();
                    while(attackOption == "s" || !player.attack(attackOption)) {
                        if (attackOption == "s") {
                            player.printAdjStates();
                        } else {
                            cout << "Invalid target." << endl;
                        }
                        cout << "Who would you like to attack? (Type \'s\' to review a list of adjacent states.)";
                        cin >> attackOption;
                    }
                    player.attack(attackOption);
                    round++;
                    break;
                }
                case 'd': // Defend
                {
                    player.defend();
                    round++;
                    break;
                }
                case 'r': // Reinforce
                {
                    player.reinforce();
                    round++;
                    break;
                }
                case 's': // Print Adjacent States
                {
                    player.printAdjStates();
                    break;
                }
                case 'q': // Quit Game
                {
                    cout << "Quitting." << endl;
                    exit = true;
                }
                default:
                {
                    cout << "Command not recognized." << endl;
                    break;
                }
            }

            if (exit) {
                return 0;
            }

        }

        player.underAttack();
        player.printAttackingQueue();
        player.checkWin();

    }

    if (player.getWon()) {
        cout << "Congratulations! You won the 2020 Civil War!" << endl;
    }

    return 0;

}