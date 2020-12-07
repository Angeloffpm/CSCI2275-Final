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

    string actions = "Type \'a\' to launch an attack.\n"
                        "Type \'d\' to defend an incoming attack.\n"
                        "Type \'r\' to reinforce army size for attack or defense.\n"
                        "Type \'s\' to review a list of adjacent states.\n"
                        "Type \'q\' to quit the game at any time.";

    US.printStates();

    int round = 1;
    char action;
    while(player.getAlive() && !player.getWon()) { // Run Game until Player Dies or Wins
    
        cout << "Round " << round << endl;
        cout << "Army Size: " << player.getArmySize() << endl;
        cout << actions << endl;
        cout << "Choose an action: " << endl;
        cin >> action;

        int currentRound = round;
        string attackOption;
        while (currentRound == round) { // Loop until an action that counts as a 'round' is taken.
            switch(action) {
                case 'a':

                    cout << "Who would you like to attack? (Type \'s\' to review a list of adjacent states.)";
                    cin >> attackOption;
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

                case 'd':

                    player.defend();
                    round++;

                case 'r':

                    player.reinforce();
                    round++;

                case 's':

                    player.printAdjStates();

                case 'q':

                    return 0;

                default:

                    cout << "Command not recognized." << endl;
            }
        }

        player.underAttack();
        player.printAttackingQueue();
        player.checkWin();

    }

    if (player.getWon()) {
        cout << "Congratulations! You won the 2020 Civil War!" << endl;
    }


}