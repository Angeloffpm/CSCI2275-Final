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
    for (int i = 1; i < states.size(); i++) {
        cout << states[i]->name << " | " << states[i]->armySize << endl;
        for (int j = 0; j < states[i]->adjStates.size() - 1; j++) {
            cout << states[i]->adjStates[j]->name << endl;
            cout << states[i]->adjStates[j]->armySize << endl;
        }
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
        State *toAdd = new State;
        string stateName;
        getline(ss, stateName, ',');
        toAdd->name = stateName;
        states.push_back(toAdd);
    }

    inStream.clear();
    inStream.seekg(0, ios::beg);
    while (getline(inStream, line)) {
        stringstream ss(line);
        getline(ss, currentElement, ',');
        State *toAdjust = findState(currentElement);
        getline(ss, currentElement, ',');
        toAdjust->armySize = stoi(currentElement);
        while (getline(ss, currentElement, ',')) {
            toAdjust->adjStates.push_back(findState(currentElement));
        }
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