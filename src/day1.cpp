#include "day1.h"
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

std::string filename = "assets/day1.input.txt";
int dial_size = 100;
int dial_max = dial_size - 1; // Since the dial starts at 0

void day1()
{
    std::cout << "Day 1\n";
    std::cout << "Part 1\n\n";
    part1();

    std::cout << "\nPart 2\n\n";
    part2();
}

// The combination is the number of times we land on 0
void part1()
{
    // 1. Keep a variable for the number we are at, and the number of times we
    // have landed on 0
    // 2. Loop over each line of the file
    // 3. Add or subtract the number from our current number (making sure to
    // loop around), and add to the 0 variable if necessary
    // 4. Close the file
    // 5. Current value of the 0 variable is the result

    int current_number{50};
    int total_zeros{0};

    std::ifstream inf{filename};

    if (!inf) {
        std::cerr << "Unable to open " << filename << '\n';
        return;
    }

    std::string str_input{};
    while (inf >> str_input) {
        std::string direction = str_input.substr(0, 1);
        std::string amount_str = str_input.substr(1);
        int direction_multiplier = direction == "L" ? -1 : 1;
        int amount = std::stoi(amount_str) * direction_multiplier;

        current_number = wrapNumber(current_number + amount);
        if (current_number == 0)
            total_zeros++;
    }

    std::cout << "The combination is: " << total_zeros << '\n';
}

// The combination is the number of times we land on 0 during a rotation (can
// include passing 0 or landing on 0)
void part2()
{
    int current_number{50};
    int total_zeros{0};

    std::ifstream inf{filename};

    if (!inf) {
        std::cerr << "Unable to open " << filename << '\n';
        return;
    }

    std::string str_input{};
    while (inf >> str_input) {
        std::string direction = str_input.substr(0, 1);
        std::string amount_str = str_input.substr(1);
        int direction_multiplier = direction == "L" ? -1 : 1;
        int amount = std::stoi(amount_str) * direction_multiplier;

        int new_number_unwrapped = current_number + amount;
        int temp_number = new_number_unwrapped;

        if (direction == "R") {
            if (temp_number >= 100) {
                int click_count =
                    static_cast<int>(std::floor(temp_number / 100));
                total_zeros += click_count;
            }
        }
        else {
            while (temp_number <= 0) {
                temp_number += 100;
                total_zeros++;
            }
            // Remove a click if we started at 0, to prevent double counting
            if (current_number == 0 && amount != 0)
                total_zeros--;
        }

        current_number = wrapNumber(new_number_unwrapped);
    }

    std::cout << "The combination is: " << total_zeros << '\n';
}

int wrapNumber(int value)
{
    return ((value % dial_size) + dial_size) % dial_size;
}
