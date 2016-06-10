#include <iostream>
#include <sstream>
#include <string>

#include "grade.hpp"
#include "student.hpp"
#include "glob.hpp"

int main()
{
    // Get number of graded artifact
    unsigned int number_of_graded_artifact = get_number();
    
    // Get graded artifacts and grade relative
    unsigned int* g1 = get_grade(number_of_graded_artifact);
    unsigned int* g2 = get_grade(number_of_graded_artifact);
    grade g = {g1, g2};

    // Get the number of student
    unsigned int number_of_student = get_number();
    
    // Get a list of all student
    student* s = get_list_of_students(number_of_student);

    // Get the number of raw score
    unsigned int number_of_student_rs = get_number();
   
    // initialize raw score
    init_raw_score(s, number_of_student, number_of_graded_artifact);

    // Update raw score for each student in the list
    update_raw_score(g, number_of_student_rs, 
                        s, number_of_student, 
                        number_of_graded_artifact);
   
    // Print total scores of each student
    print_total_score(s, number_of_student);

    // Get the number of cutpoint set
    unsigned int number_of_cutpoint_set = get_number();
    
    // Print the letter grade of each student for each cutpoint set
    for (int i = 0; i < number_of_cutpoint_set; i++)
    {
        // Get the current cutpoint array
        double* cutpoint = get_cutpoint();
        
        std::cout << "CUTPOINT SET " << i+1 << std::endl;
        
        // Print each student with the letter grade
        print_letter_grade(s, number_of_student, cutpoint);
     
        // Deallocate the cutpoint array 
        delete[] cutpoint;
    }
    
    // Deallocate the graded artifact and student array
    
    delete[] g1;
    delete[] g2;
    delete[] s;

    return 0;
}
