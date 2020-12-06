#include <iostream>
#include <fstream>
#include <sstream>
#include "UnitedStates.h"

using namespace std;

// ==============
// Public Methods
// ==============

UnitedStates::UnitedStates(string data) {
    buildMap(data);
}

void UnitedStates::printStates() {
    for (int i = 0; i < states.size(); i++) {
        cout << states[i]->name << " | " << states[i]->armySize << endl;
    }
}

// ==============
// Private Methods
// ==============

void UnitedStates::buildMap(string data) {

    ifstream inStream;
    string line;
    string currentElement;

    inStream.open(data);

    if (!inStream) {
        cout << "Could not open file." << endl;
        return;
    }

    while (getline(inStream, line)) {
        stringstream ss(line);
        State *toAdd;

        getline(ss, currentElement, ','); // Name
        if (findState(currentElement) != nullptr) {
            toAdd = findState(currentElement);
        } else {
            toAdd = new State;
            toAdd->name = currentElement;
        }

        getline(ss, currentElement, ','); // Army Size
        toAdd->armySize = stoi(currentElement);

        while (getline(ss, currentElement, ',')) { // Adjacent States
            if (findState(currentElement) != nullptr) {
                toAdd->adjStates.push_back(findState(currentElement));
            } else {
                State *newAdjState = new State;
                newAdjState->name = currentElement;
                toAdd->adjStates.push_back(newAdjState);
            }
        }
        states.push_back(toAdd);
    }
    inStream.close();
}

State* UnitedStates::findState(string name) {
    for (int i = 0; i < states.size(); i++) {
        if (states[i]->name == name) {
            return states[i];
        }
    }
    return nullptr;
}