#include "utilities.h"
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>

// Adapted from task 1 solution
int addCalibrationValues(std::vector<std::string> input_vector) {
    std::string s;
    std::vector<int> calibration_values;
    char first, last;

    for (int line_number = 0; line_number != input_vector.size(); ++line_number) {

        s = input_vector[line_number];

        // Find first number
        for (int i = 0; i != s.size(); ++i) {
            if (std::isdigit(s[i])) {
                first = s[i];
                break;
            }
        }

        // Find last number
        for (int i = s.size(); i >= 0; --i) {
            if (std::isdigit(s[i])) {
                last = s[i];
                break;
            }
        }

        std::string result = std::string(1,first) + std::string(1,last);
        calibration_values.push_back(std::stoi(result));
    }


    // Add numbers
    int calibration_sum = 0;
    for (auto i = calibration_values.begin(); i != calibration_values.end(); ++i) {
        calibration_sum += (*i);
    }

    return calibration_sum;
}

int main() {
    // TASK 1
    std::vector<std::string> puzzle_input = string_input_to_vector("day1.txt");

    std::cout << addCalibrationValues(puzzle_input) << std::endl;

    // TASK 2
    // Replace every word with the corresponding number

    // Create reference map
    std::map<std::string, std::string> number_ref;
    number_ref["one"]   = "1";
    number_ref["two"]   = "2";
    number_ref["three"] = "3";
    number_ref["four"]  = "4";
    number_ref["five"]  = "5";
    number_ref["six"]   = "6";
    number_ref["seven"] = "7";
    number_ref["eight"] = "8";
    number_ref["nine"]  = "9";

    // Get vector of keys
    std::vector<std::string> keys = {"one", "two", "three",
                                     "four", "five", "six",
                                     "seven", "eight", "nine"
                                    };
    std::string s;
    std::vector<std::string> modified_vector;

    std::string rep_string;
    std::string rep_num;
    std::map<int, std::string> rep_positions;

    // Loop through the initial input
    for (int line_number = 0; line_number != puzzle_input.size(); ++line_number) {
        s = puzzle_input[line_number];
        rep_positions.clear();
        
        // Loop through the vector of number words
        for (int i = 0; i != keys.size(); ++i) {
            rep_string = keys[i];
            rep_num = number_ref[rep_string];
            int pos = s.find(rep_string);

            // Make notes of replacements
            while (pos != std::string::npos) {
                rep_positions[pos] = rep_num;
                pos = s.find(rep_string, pos + 1);
            }
        }

        // Insert numbers into the string
        int offset = 0;
        for (auto i = rep_positions.begin(); i != rep_positions.end(); ++i) {
            offset++;
            s.insert((*i).first + offset, (*i).second);
        }

        modified_vector.push_back(s);
        //std::cout << s << std::endl;
    }
    
    std::cout << addCalibrationValues(modified_vector) << std::endl;

    return 0;
}