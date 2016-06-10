#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "grade.hpp"

struct student
{
    unsigned int student_id;
    char grade_option;
    std::string name;
    unsigned int* raw_score;
    double total_grade;
};


student* get_list_of_students(const unsigned int& number_of_student);

void init_raw_score(student* student_list, 
                    const unsigned int& student_list_size,
                    const unsigned int& grade_size);


void update_raw_score(const grade& g, 
                        const unsigned int& number_of_student_rs, 
                        student* student_list, 
                        const unsigned int& student_list_size, 
                        const unsigned int& grade_size);


double calculate_total_grade(const grade& g, 
                                const unsigned int* raw_score, 
                                const unsigned int& grade_size);


void print_total_score(student* student_list, 
                        const unsigned int& number_of_student);


void print_letter_grade(student* student_list, 
                        const unsigned int& number_of_student, 
                        const double* cutpointl);


#endif // STUDENT_HPP
