#include <iostream>
#include "UnitedStates.h"

class Player {
    public:
        void attack(string toAttack); // Attack an Adjacent State
        void reinforce(); // Increase army size
        void defend(); // Boost defenses
    private:
        State* playerState;
};