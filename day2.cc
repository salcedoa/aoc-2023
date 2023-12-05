#include "utilities.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>

class Game {
    public:
        Game(int id, int r, int g, int b) : _id(id), _red(r), _green(g), _blue(b) {}

        int getID() const { return _id; }
        int getRed() const { return _red; }
        int getGreen() const { return _green; }
        int getBlue() const { return _blue; }

        // Check if there are enough cubes
        bool enoughRed(int target) {
            if (target >= _red) { return true; }
            return false;
        }

        bool enoughGreen(int target) {
            if (target >= _green) { return true; }
            return false;
        }

        bool enoughBlue(int target) {
            if (target >= _blue) { return true; }
            return false;
        }

    private:
        int _id, _red, _green, _blue;
};

int main() {
    std::vector<std::string> puzzle_input = string_input_to_vector("day2.txt");

    // TASK 1
    // Create the game objects
    std::vector<Game> games;
    std::string round;
    std::string line;

    for (int i = 0; i != puzzle_input.size(); ++i) {
        line = puzzle_input[i];
        int max_red = 0, max_blue = 0, max_green = 0;

        // Find maximum RED cubes
        int pos = line.find("red");

        while (pos != std::string::npos) {
            std::string number_pos = line.substr(pos-3, 2);

            int cubes = std::stoi(number_pos);

            if (cubes > max_red) {
                max_red = cubes;
            }

            pos = line.find("red", pos + 1);
        }

        // Find maximum GREEN cubes
        pos = line.find("green");

        while (pos != std::string::npos) {
            std::string number_pos = line.substr(pos-3, 2);

            int cubes = std::stoi(number_pos);

            if (cubes > max_green) {
                max_green = cubes;
            }

            pos = line.find("green", pos + 1);
        }

        // Find maximum BLUE cubes
        pos = line.find("blue");

        while (pos != std::string::npos) {
            std::string number_pos = line.substr(pos-3, 2);

            int cubes = std::stoi(number_pos);

            if (cubes > max_blue) {
                max_blue = cubes;
            }

            pos = line.find("blue", pos + 1);
        }

        // Create game instance
        Game new_game(i+1, max_red, max_green, max_blue);
        games.push_back(new_game);
    }

    // Check if each game is possible
    int id_sum = 0;
    for (auto g = games.begin(); g != games.end(); ++g) {
        if ((*g).enoughRed(12) && (*g).enoughGreen(13) && (*g).enoughBlue(14)) {
            id_sum += (*g).getID();
        }
    }

    std::cout << id_sum << std::endl;

    // TASK 2

    // Make a new vector of games with smallest possible number of cubes of each colour
    std::vector<Game> games_min;

    for (int i = 0; i != puzzle_input.size(); ++i) {
        line = puzzle_input[i];
        int min_red = 0, min_blue = 0, min_green = 0;

        // Find an initial amount of RED cubes
        int pos = line.find("red");
        std::string number_pos = line.substr(pos-3, 2);
        int cubes = std::stoi(number_pos);
        min_red = cubes;

        // Find minimum RED cubes
        while (pos != std::string::npos) {
            std::string number_pos = line.substr(pos-3, 2);

            cubes = std::stoi(number_pos);

            if (cubes < min_red) {
                min_red = cubes;
            }

            pos = line.find("red", pos + 1);
        }

        // Find initial an amount of GREEN cubes
        pos = line.find("green");
        number_pos = line.substr(pos-3, 2);
        cubes = std::stoi(number_pos);
        min_green = cubes;

        // Find minimum GREEN cubes
        while (pos != std::string::npos) {
            number_pos = line.substr(pos-3, 2);

            cubes = std::stoi(number_pos);

            if (cubes > min_green) {
                min_green = cubes;
            }

            pos = line.find("green", pos + 1);
        }

        // Find initial an amount of BLUE cubes
        pos = line.find("blue");
        number_pos = line.substr(pos-3, 2);
        cubes = std::stoi(number_pos);
        min_blue = cubes;

        // Find minimum BLUE cubes
        while (pos != std::string::npos) {
            std::string number_pos = line.substr(pos-3, 2);

            int cubes = std::stoi(number_pos);

            if (cubes > min_blue) {
                min_blue = cubes;
            }

            pos = line.find("blue", pos + 1);
        }

        // Create game instance
        Game new_game(i+1, min_red, min_green, min_blue);
        games_min.push_back(new_game);
    }

    // Find the powers of each game and add them up
    int power_sum = 0;
    int power;
    for (auto g = games.begin(); g != games.end(); ++g) {
        power = (*g).getRed() * (*g).getGreen() * (*g).getBlue();
        power_sum += power;
    }

    std::cout << power_sum << std::endl;

    return 0;
}