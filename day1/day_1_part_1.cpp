#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("../day_1_input.txt");
    if (file.is_open()) {
        long calibration_sum = 0;
        string line;
        while (file.good()) {
            getline(file, line);
            int tens_digit = -1;
            int ones_digit = -1;

            for (char c: line) {
                if (isdigit(c)) {
                    if (tens_digit == -1) {
                        tens_digit = c - '0';
                    }
                    ones_digit = c - '0';
                }
            }
            calibration_sum += tens_digit * 10 + ones_digit;
        }
        cout << calibration_sum;
    }
    return 0;
}
