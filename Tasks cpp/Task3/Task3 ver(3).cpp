//THIS CODE ALLOWS THE INPUT OF lowercase 's' & 'p' FOR LAZY USERS LIKE YOURS TRULY :D
#define _CRT_SECURE_NO_WARNINGS // To use strtok instead of strtok_s
#include <iostream>
#include <vector>
#include <cstring> // To use `strtok` function
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
    (void)strtod(s.c_str(), &p); 
    /*
  Ignoring the return value is fine in this case, because the function is only used to check if the string is a number.
     In the is_number function, strtod(s.c_str(), &p) is used to check if the entire string s can be interpreted as a number:
    - s.c_str() is the string to check.
    - &p is a pointer to a char that will be set to point to any part of the string that couldn't be converted.
    */
    return *p == 0;
}

int main() {
    string circuit_description;
    cout << "Enter circuit description: ";
    getline(cin, circuit_description);

    vector<vector<double>> resistances_stack;
    vector<char> types;
    char* token = strtok(&circuit_description[0], " ");

    while (token != NULL) {
        string token_str(token);
        if (token_str == "E" || token_str == "e") {
            if (!types.empty()) {
                char type = types.back();
                types.pop_back();
                vector<double> current_resistances = resistances_stack.back();
                resistances_stack.pop_back();
                double equivalent_resistance = calculate_resistance(current_resistances, type);
                if (!resistances_stack.empty()) {
                    resistances_stack.back().push_back(equivalent_resistance);
                }
                else {
                    resistances_stack.push_back(vector<double>{equivalent_resistance});
                }
            }
        }
        else if (token_str == "s" || token_str == "p" || token_str == "S" || token_str == "P") {
            token_str = toupper(token_str[0]); // here we convert s & p to uppercase to handle the calculate_resistance function, we assume a user might be too lazy to uppercase the letters (example: me XD)
            types.push_back(token_str[0]);
            resistances_stack.push_back(vector<double>{});
        }
        else {
            if (is_number(token_str)) {
                resistances_stack.back().push_back(stod(token_str));
            }
            else {
                cout << "Wrong Circuit Description" << endl;
                return 1;
            }
        }

        token = strtok(NULL, " ");
    }

    cout << "Equivalent resistance: " << resistances_stack.back()[0] << " ohms" << endl;

    cout << "Enter voltage: ";
    double voltage;
    cin >> voltage;
    cout << "Current: " << voltage / resistances_stack.back()[0] << " A" << endl;

    return 0;
}
