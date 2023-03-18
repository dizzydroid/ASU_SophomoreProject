//USING STRINGSTREAM FUNCTION FOR A MORE SIMPLIFIED CODE
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// A function to calculate total resistance in series
double seriesResistance(double r1, double r2, double r3) {
    return r1 + r2 + r3;
}

// A function to calculate total resistance in parallel
double parallelResistance(double r1, double r2, double r3) {
    return 1 / (1 / r1 + 1 / r2 + 1 / r3);
}

// A function to calculate current using Ohm's law
double current(double v, double r) {
    return v / r;
}
int main() {
    string input; //entire user input string
    string voltage; //user input string for voltage
    char type; //"S" for series or "P" for parallel
    double v; //voltage applied to the circuit
    double r1, r2, r3; //values of resistances
    double rt; //value of total resistance
    double i; //current

    cout << "Enter Circuit type (S or P) and resistances (separated by spaces): ";
    getline(cin, input); //get entire line as a single string for circuit description

    stringstream ss(input); //create a stringstream object from the input string

    ss >> type >> r1 >> r2 >> r3; //extract the values from the stringstream object

    cout << "Enter voltage applied to the circuit: ";
    getline(cin, voltage); //get entire line as a single string for voltage

    //convert the voltage string to double using stod 
    v = stod(voltage);

    if (type == 'S' || type == 's') {
        rt = seriesResistance(r1, r2, r3);
        cout << "Total resistance in series: " << rt << " ohms\n";
        i = current(v, rt);
        cout << "Current in series: " << i << " amps\n";
    }

    else if (type == 'P' || type == 'p') {
        rt = parallelResistance(r1, r2, r3);
        cout << "Total resistance in parallel: " << rt << " ohms\n";
        i = current(v, rt);
        cout << "Current in parallel: " << i << " amps\n";
    }

    else {
        cout << "Invalid input.\n";
    }

    return 0;
}
