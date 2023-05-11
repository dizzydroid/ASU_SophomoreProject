//THIS CODE GIVES OUTPUTS BUT DOES NOT CORRECTLY HANDLE NESTED CIRCUITS
/*
The code seems to be operating under the assumption that when a sub-circuit ends (i.e., an 'e' or 'E' is encountered), 
it only needs to calculate the resistance for the current list of resistances. This is not always the case, as we can have nested circuits.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

double calculate_resistance(vector<double>& resistances, char type) {
    double total_resistance = 0.0;

    if (type == 'S') {
        for (double resistance : resistances) {
            total_resistance += resistance;
        }
    }
    else {  // Parallel circuit
        for (double resistance : resistances) {
            total_resistance += 1.0 / resistance;
        }
        total_resistance = 1.0 / total_resistance;
    }

    return total_resistance;
}

bool is_number(const string& s) {
    char* p;
    strtod(s.c_str(), &p);
    return *p == 0;
}

int main() {
    string circuit_description;
    cout << "Enter circuit description: ";
    getline(cin, circuit_description);

    vector<double> resistances;
    vector<char> types;
    char* token = strtok(&circuit_description[0], " ");

    while (token != NULL) {
        string token_str(token);
        if (token_str == "E" || token_str == "e") {
            if (!types.empty()) {
                char type = types.back();
                types.pop_back();
                double equivalent_resistance = calculate_resistance(resistances, type);
                resistances.clear();
                resistances.push_back(equivalent_resistance);
            }
        }
        else if (token_str == "S" || token_str == "P") {
            types.push_back(token_str[0]);
        }
        else {
            if (is_number(token_str)) {
                resistances.push_back(stod(token_str));
            }
            else {
                cout << "Wrong Circuit Description" << endl;
                return 1;
            }
        }

        token = strtok(NULL, " ");
    }

    cout << "Equivalent resistance: " << resistances[0] << " ohms" << endl;

    cout << "Enter voltage: ";
    double voltage;
    cin >> voltage;
    cout << "Current: " << voltage / resistances[0] << " A" << endl;

    return 0;
}
