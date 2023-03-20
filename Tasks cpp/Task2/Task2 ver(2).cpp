//CODE WORKS PERFECTLY, BUT IS NOT A PERFECT SOLUTION TO THE TASK DUE TO USAGE OF CONSTRAINT; ASSUMING MAX. 100 RESISTORS.
#include <iostream>
#include <string>
using namespace std;


int main() {
    // declare variables
    double resistances[100]{}; // assuming max 100 resistors
    char connection;
    double voltage;
    double totalResistance;
    double current;

    // get input from user
    cout << "Enter S for series or P for parallel followed by resistances separated by spaces followed by E: ";

    cin >> connection; // get connection type

    int i{}; // index for array
    while (true) {
        string input;
        cin >> input;
        if (input == "E") {
            break; // end input
        }
        else {
            resistances[i] = stod(input); // convert string to double
            i++; // increment "i"
        }
    }

    cout << "Enter voltage: ";
    cin >> voltage;

    // calculate total resistance
    if (connection == 'S' || connection == 's') {
        // series connection: Rt = R1 + R2 + ... + Rn
        totalResistance = 0;
        for (int j = 0; j < i; j++) {
            totalResistance += resistances[j];
        }
    }
    else if (connection == 'P' || connection == 'p') {
        // parallel connection: 1/Rt = 1/R1 + ... + 1/Rn 
        double inverseTotalResistance = 0;
        for (int j = 0; j < i; j++) {
            inverseTotalResistance += 1 / resistances[j];
        }
        totalResistance = 1 / inverseTotalResistance;
    }
    else {
        // invalid connection type: print error message and exit program 
        cout << "Wrong Circuit Description" << endl;
        return 1;
    }

    // calculate current 
    current = voltage / totalResistance;

    cout << "Total Resistance: " << totalResistance << endl;
    cout << "Current: " << current << endl;

    return 0; 
}
