#include <iostream>
#include <string>
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
	char type; //"S" for series or "P" for parallel
	double v; //voltage applied to the circuit
	double r1, r2, r3; //values of resistances
	double rt; //value of totla resistance
	double i; //current

	cout << "Enter Circuit type (S or P), voltage and resistances: ";
	getline(cin, input); //get entire line as a single string

	type = input[0]; //first character is circuit type

	//convert the rest of the string to double using stod
	v = stod(input.substr(2, input.find(' ', 2) - 2));
	int space = input.find(' ', 2); //position of first space after voltage
	r1 = stod(input.substr(space + 1, input.find(' ', space + 1) - space - 1));
	space = input.find(' ', space + 1); //position of second space after r1
	r2 = stod(input.substr(space + 1, input.find(' ', space + 1) - space - 1));
	space = input.find(' ', space + 1); //position of third space after r2
	r3 = stod(input.substr(space + 1));

	if (type == 'S') {
		rt = seriesResistance(r1, r2, r3);
		cout << "Total resistance in series: " << rt << " ohms\n";
		i = current(v, rt);
		cout << "Current in series: " << i << " amps\n";
	}

	else if (type == 'P') {
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