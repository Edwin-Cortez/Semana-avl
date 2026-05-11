#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student {
    int student_id;
    std::string full_name;
    std::string career;
    int semester;
    float gpa;
    int skill_score;
};

#endif// STUDENT_H