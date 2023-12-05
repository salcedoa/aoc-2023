#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "utilities.h"

// Convert text file with input seperated by new lines and return a vector
std::vector<std::string> string_input_to_vector(const std::string filename) 
{
    std::ifstream file_input(filename);

    // Check if file is open
    if (!file_input.is_open()) 
    {
        std::cerr << "Error opening the file."  << std::endl;
        return {};
    }

    // Convert file contents to vector
    std::vector<std::string> strings;
    std::string s;
    while (file_input >> s)
    {
        strings.push_back(s);
    }

    file_input.close();

    return strings;
}