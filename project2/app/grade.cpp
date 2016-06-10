#include <iostream>
#include <sstream>
#include <string>

#include "grade.hpp"

unsigned int* get_grade(const unsigned int& size)
{
    // Takes the number of graded artifact as argument
    // read the line and returns an array of integer represents grade artifacts or relative weight

    unsigned int* array = new unsigned int[size];
    unsigned int i = 0;
    
    std::string line;
    std::getline(std::cin, line);
    
    std::stringstream ssin(line);
   
    // split the line by space and add to array to return
    while(ssin.good() && i < size)
    {
        ssin >> array[i];
        i++;
    }
    return array;
}


double* get_cutpoint()
{
    // Returns a cutpoint array including 4 values
    // represent cutpoints for A,B,C, and D
    double* array = new double[4];
    unsigned int i = 0;

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ssin(line);

    while(ssin.good() && i < 4)
    {
        ssin >> array[i];
        i++;
    }
    return array;
}
