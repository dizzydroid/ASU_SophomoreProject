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
    cout << "Total resistances: " << rt << endl;
    cout << "Circuit current = " << v / rt << endl;
    return 0;
}
