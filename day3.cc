#include "utilities.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cctype>

// To record information about each number
class LineNumber() {
    public:
        LineNumber(int n, int s, int e) :  _num(n), _pos_start(s), _pos_end(e) {} 
    private:
        int _num, _pos_start, _pos_end;
};

int main() {
    std::vector<std::string> puzzle_input = string_input_to_vector("test.txt");

    // TASK 1
    // Every number will be evaluated
    
    // First line
    std::vector<int> line_nums;
    int start_pos = 0, end_pos = 0, length = 0;
    std::string top_line = "", bottom_line = puzzle_input[1], current_line = puzzle_input[0];
    
    // Collect numbers on the current line
    std::string temp = "";
    for (int i = 0; i != current_line.size(); ++i) {
        if (std::isdigit(current_line[i])) {
            while (current_line[i] != '.' || current_line[i] != '\n' || current_line[i] != '\0') {
                temp.append(current_line[i]);
            }
        }
        line_nums.push_back(temp);
    }

    for (int i = 1; i != puzzle_input.size()-1; ++i) {
        // identify numbers
        int start_pos = 0, end_pos = 0;
        std::string top_line = "", bottom_line = "";
        puzzle_input[i];
        
    }

    return 0;
}