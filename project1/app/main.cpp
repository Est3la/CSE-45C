#include <iostream>
#include <string>

#include "location.hpp"


int main()
{
    location start_location = get_location();
    start_location.distance = 0;


    unsigned int number = get_number_of_location();

   
    location min, max; max = start_location; 

    for (unsigned j = 0; j < number; j++)
    {   
        location destination = get_location();
        destination.distance = calculate_distance(start_location, destination);
        if (j==0) min = destination;
        if (destination.distance < min.distance) min = destination;
        if (destination.distance > max.distance) max = destination;
    }
    
    std::cout << "Start Location: " << print_location(start_location);
    std::cout << "Closest Location: " << print_location(min);
    std::cout << "Farthest Location: " << print_location(max);
    return 0;
}
