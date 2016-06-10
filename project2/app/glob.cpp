#include <iostream>
#include <string>

#include "glob.hpp"

unsigned int get_number()
{
    // return an unsigned int represents the desired quantity

    unsigned int number;
    std::cin >> number;

    std::string temp;
    std::getline(std::cin, temp);

    return number;
}
