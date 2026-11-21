//****************This is the line of 80 characters in length*******************
// Author: Intesar Qifayat
// date: 11/13/25
// CS1428 Lab
// Lab 10 - Fishing Trip Tracker
// Description: Simulates a fishing trip log that records caught fish.

#include <iostream>
#include <string>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <iomanip>
#include <limits>
#include <cmath>
using namespace std;

void displayFish(const string species[], const double weights[], int count);
void addFish(string species[], double weights[], int &count, int maxSize);
void catchFish(string species[], double weights[], int &count, double &totalWeight);

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    const int MAXFISH = 10;
    int fishCount = 0;
    double totalWeightCaught = 0.0;

    string fishSpecies[MAXFISH];
    double fishWeights[MAXFISH];
    int choice;
    char continueInput;

    cout << "=== FISHING TRIP TRACKER ===" << endl;
    cout << "Log fish species and their weights" << endl;

    do {
        cout << endl;
        cout << "Current Fish:" << endl;
        displayFish(fishSpecies, fishWeights, fishCount);
        cout << endl;

        cout << "Choose an action:" << endl;
        cout << "1. Display fish log" << endl;
        cout << "2. Add a fish seen" << endl;
        cout << "3. Catch a fish" << endl;
        cout << "Enter choice (1-3): ";

        while (!(cin >> choice) || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please enter (1-3): ";
        }

        switch (choice) {
            case 1:
                cout << endl << "--- Fish Log ---" << endl;
                displayFish(fishSpecies, fishWeights, fishCount);
                cout << "----------------" << endl;
                break;
            case 2:
                addFish(fishSpecies, fishWeights, fishCount, MAXFISH);
                break;
            case 3:
                catchFish(fishSpecies, fishWeights, fishCount, totalWeightCaught);
                break;
        }

        cout << endl << "Continue? (y/n): ";
        cin >> continueInput;
    } while (continueInput == 'y' || continueInput == 'Y');

    cout << endl;
    cout << "Final Fish Log:" << endl;
    displayFish(fishSpecies, fishWeights, fishCount);

    totalWeightCaught = round(totalWeightCaught * 10.0) / 10.0;
    cout << "Total Weight of Fish Kept: "
         << fixed << setprecision(1) << totalWeightCaught << " lbs" << endl;

    return 0;
}

void displayFish(const string species[], const double weights[], int count) {
    if (count == 0) {
        cout << "No fish logged" << endl;
    } else {
        for (int i = 0; i < count; i++) {
            cout << (i + 1) << ". " << species[i] << " | "
                 << fixed << setprecision(1) << weights[i] << " lbs" << endl;
        }
    }
}

void addFish(string species[], double weights[], int &count, int maxSize) {
    if (count >= maxSize) {
        cout << "Lake is full. Cannot add new fish" << endl;
    } else {
        cout << "Enter fish species: ";
        cin >> species[count];

        double rawWeight = 0.5 + static_cast<double>(rand()) / (RAND_MAX / (25.0 - 0.5));
        weights[count] = round(rawWeight * 10.0) / 10.0;

        cout << "Fish " << species[count] << " added" << endl;
        count++;
    }
}

void catchFish(string species[], double weights[], int &count, double &totalWeight) {
    if (count == 0) {
        cout << "No fish to catch!" << endl;
        return;
    }

    string speciesToFind;
    cout << "Enter fish species to catch: ";
    cin >> speciesToFind;

    bool found = false;
    int foundIndex = -1;

    for (int i = 0; i < count; i++) {
        if (species[i] == speciesToFind) {
            found = true;
            foundIndex = i;
            break;
        }
    }

    if (found) {
        totalWeight += weights[foundIndex];
        cout << "Fish " << species[foundIndex] << " caught! Weight added to total." << endl;
        for (int i = foundIndex; i < count - 1; i++) {
            species[i] = species[i + 1];
            weights[i] = weights[i + 1];
        }
        count--;
    } else {
        cout << "Fish not found" << endl;
    }
}
