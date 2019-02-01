#ifndef STUDENT_H
#define STUDENT_H
#include "Mark.h"

class Student
{
    public:
        Student(char name[30],Mark marks);
        Student();
        void printStudentData();
        Mark getStudentMarks();
        


    private:
    char name[30];
    Mark marks;
};

#endif // STUDENT_H
