#include <iostream>
#include <sstream>
#include <string>

#include "student.hpp"


student get_student()
{
    // Return a student with student id,
    // grade option, and name

    student s;
    std::cin >> s.student_id >> s.grade_option;
    std::cin.ignore(1);
    std::getline(std::cin, s.name);
    return s;
}

student* get_list_of_students(const unsigned int& number_of_student)
{
    // Takes the number of student
    // Returns an array of students

    student* student_list = new student[number_of_student];
    for(int i = 0; i < number_of_student; i++)
    {
        student_list[i] = get_student();
    }
    return student_list;
}

unsigned int* get_raw_score(const unsigned int& size)
{
    // Takes the number of graded artifacts
    // Returns an array of raw score for a student with student id

    unsigned int* raw_score = new unsigned int[size];
    unsigned int i = 0;

    std::string line;
    std::getline(std::cin, line);

    std::stringstream ssin(line);
    
    while(ssin.good() && i < size)
    {
        ssin >> raw_score[i];
        i++;
    }
    return raw_score;
}

double calculate_total_grade(const grade& g, 
                                const unsigned int* raw_score, 
                                const unsigned int& grade_size)
{
    // Takes structure grade, raw score and number of graded artfacts
    // Returns the total grade in double

    double total = 0;
    for(int i = 0; i < grade_size; i++)
    {
        total += static_cast<double>(raw_score[i])/
                    g.graded_artifact[i]* 
                    g.relative_weight[i];
    }
    return total;
}

void zeroFill(unsigned int* a, 
                const unsigned int& grade_size)
{
    // Fill an array of all 0s

    for (int i = 0; i < grade_size; i++)
    {
        a[i]=0;
    }    
}

void init_raw_score(student* student_list, 
                    const unsigned int& student_list_size,
                    const unsigned int& grade_size)
{
    // Initialize the raw score of all student to take the 0 values
    
    unsigned int* raw_score_zero = new unsigned int[grade_size];
    zeroFill(raw_score_zero,grade_size);

    for (int i = 0; i < student_list_size; i++)
    {
        student_list[i].raw_score = &raw_score_zero[0];            
    }

    // deallocate the raw score zero array
    delete[] raw_score_zero;
}

void update_raw_score(const grade& g, 
                        const unsigned int& number_of_student_rs, 
                        student* student_list, 
                        const unsigned int& student_list_size, 
                        const unsigned int& grade_size)
{
 
    // Updates the raw score of all student in the students array

    for(int i = 0; i < number_of_student_rs; i++)
    {
        unsigned int* raw_score = get_raw_score(grade_size+1);        
        for(int j = 0; j < student_list_size; j++)
        {
            if(student_list[j].student_id == raw_score[0])
            {
                student_list[j].raw_score = &raw_score[1];
                student_list[j].total_grade = calculate_total_grade(g, &raw_score[1], grade_size);
            }
        }

        // deallocated the raw score array
        delete[] raw_score;
    }
}

std::string calculate_letter_grade(char& grade_option, 
                                    const double& total, 
                                    const double* cutpoint)
{
    // Takes grade option, total, and cutpoint
    // Returns the letter grade

    switch(grade_option)
    {
        case 'P':
        {
            if (total >= double(cutpoint[2])) {return "P";} 
            else {return "NP";}
            break;
        }
        case 'G':
        {
            if (total >= double(cutpoint[0])) {return "A";}
            else
            {
                if (total >= double(cutpoint[1])) {return "B";}
                else
                {
                    if (total >= double(cutpoint[2])) {return "C";}
                    else
                    {
                        if (total >= double(cutpoint[3])) {return "D";}
                        else {return "F";}
                    }
                }
            }
            break;
        }
        default:
            return "";
    }
}

void print_total_score(student* student_list, 
                        const unsigned int& number_of_student)
{
    // Takes the students array and number of student
    // Prints the total score of each student based on the required format
    
    std::cout << "TOTAL SCORES" << std::endl;
    for (int i = 0; i < number_of_student; i++)
    {
        std::cout << student_list[i].student_id << " "
                    << student_list[i].name << " "
                    << student_list[i].total_grade << std::endl;
    }
}

void print_letter_grade(student* student_list, 
                        const unsigned int& number_of_student, 
                        const double* cutpoint)
{
    // Takes the students array, number of student, and cutpoint array
    // Prints the letter grade of each student based on cutpoint
    // following the required format

    for(int i = 0; i < number_of_student; i++)
    {
        std::cout << student_list[i].student_id << " "
                    << student_list[i].name << " "
                    << calculate_letter_grade(student_list[i].grade_option, 
                                            student_list[i].total_grade, 
                                            cutpoint) << std::endl;
    }
}
