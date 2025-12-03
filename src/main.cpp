#include "day1.h"
#include "day2.h"
#include <chrono>
#include <iostream>

void runDay(int day);

int main()
{
    std::cout << "Welcome to my Advent of Code 2025!\n-----\n";
    std::cout << "Select a day between 1 - 12: ";
    int day{};
    std::cin >> day;
    std::cout << "-----\n";

    auto start = std::chrono::high_resolution_clock::now();

    runDay(day);

    auto end = std::chrono::high_resolution_clock::now();
    auto duration_us =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto duration_ms =
        std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Executed in: " << duration_us.count() << "µs\n";
    std::cout << "             " << duration_ms.count() << "ms\n";
    return 0;
}

void runDay(int day)
{
    switch (day) {
    case 1:
        day1();
        break;
    case 2:
        day2();
        break;
    default:
        std::cout << "Invalid day selected. Terminating\n";
        break;
    }
}