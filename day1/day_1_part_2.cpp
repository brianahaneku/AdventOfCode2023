#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream file("../day_1_input.txt");
    if (file.is_open()) {
        long calibration_sum = 0;
        string line;
        vector<string> numbers = {"zero", "one", "two", "three", "four",
                          "five","six", "seven", "eight", "nine"};
        while (file.good()) {
            getline(file, line);
            int tens_digit = -1;
            int tens_digit_index = line.length();
            int ones_digit = -1;
            int ones_digit_index = -1;
            for (int i = 1; i < numbers.size(); i++) {
                int first_occurence = line.find(numbers[i]);
                if (first_occurence != string::npos && first_occurence < tens_digit_index) {
                    tens_digit_index = first_occurence;
                    tens_digit = i;
                }
                int last_occurence = line.rfind(numbers[i]);
                if (last_occurence != string::npos && last_occurence > ones_digit_index) {
                    ones_digit_index = last_occurence;
                    ones_digit = i;
                }
            }
            cout << tens_digit << ones_digit << endl;
            for (int i = 0; i < line.length(); i++) {
                if (isdigit(line[i])) {
                    if (i < tens_digit_index) {
                        tens_digit = line[i] - '0';
                        break;
                    }
                }
            }
            for (int i = line.length() - 1; i >= 0; i--) {
                if (isdigit(line[i])) {
                    if (i > ones_digit_index) {
                        ones_digit = line[i] - '0';
                        break;
                    }
                }
            }
            calibration_sum += tens_digit * 10 + ones_digit;
        }
        cout << calibration_sum;
    }
    return 0;
}
