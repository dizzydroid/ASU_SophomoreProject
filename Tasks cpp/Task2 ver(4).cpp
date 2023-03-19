#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Define a function that can handle series circuits
double Series(string input) {
    double SeriesResistance = 0;
    input = input.substr(2, input.length());
    while (toupper(input[0]) != 'E') //we assume a user might be lazy and forgets to capitalize 'E' :D
    {
        SeriesResistance += stod(input);
        input = input.substr(input.find(" ") + 1, input.length());
    }
    return SeriesResistance;
}
// Define a function that can handle parallel circuits
double Parallel(string input) {
    double ParallelResistance = 0;
    input = input.substr(2, input.length());
    while (toupper(input[0]) != 'E')
    {
        ParallelResistance += pow(stod(input), -1);
        input = input.substr(input.find(" ") + 1, input.length());
    }
    return pow(ParallelResistance, -1);
}

int main() {
    //declare variables
    string input; // Declare a variable to store the circuit description
    cout << "Enter circuit type (S or P) and resistances (separated by spaces): ";
    getline(cin, input); // Get user input for the circuit description

    double v; // Declare a variable to store voltage applied 
    cout << "Voltage applied: ";
    cin >> v; // Get user input for voltage applied

    double rt; // Declare a variable to store total resistance

    switch (toupper(input[0])) // Use toupper function to convert input to uppercase
    {
    case 'S': // If circuit type is S
        rt = Series(input); // Call series function
        break;
    case 'P': // If circuit type is P
        rt = Parallel(input); // Call parallel function
        break; 
    default: // If circuit type is neither S nor P
        cout << "Wrong Circuit Type." << endl;
        return 1; // Terminate program with error code 1
    }
    cout << "Total resistances: " << rt << endl;
    cout << "Circuit current = " << v / rt << endl;
    return 0;
}

/* ALTERNATIVE TO SWITCH CASE STATEMENT:
   if (toupper(input[0]) == 'S')
    {
        rt = Series(input);
    }
    else if (toupper(input[0]) == 'P')
    {
        rt = Parallel(input);
    }
    else
    {
        cout << "Wrong Circuit Description." << endl;
        return 1;
    }
*/


