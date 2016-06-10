#ifndef GRADE_HPP
#define GRADE_HPP

struct grade
{
    unsigned int* graded_artifact;
    unsigned int* relative_weight;
};



unsigned int* get_grade(const unsigned int& size);

double* get_cutpoint();


#endif // GRADE_HPP
