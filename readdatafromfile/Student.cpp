#include "Mark.h"
#include "Student.h"
#include <iostream>
#include "string.h"
#include <fstream>
using namespace std;


Student::Student(char name[30],Mark marks)
{
    this->marks=marks;
    strcpy(this->name,name);
}

Student::Student()
{
    
}

void Student::printStudentData()
{

    ofstream mytempfile;
    mytempfile.open ("temp.txt", std::ios_base::out);
    //mytempfile<<"Student data : "<<endl;
    mytempfile<<"student name : "<<this->name<<endl;
    mytempfile<<"math mark : "<<this->marks.getMath()<<endl;
    mytempfile<<"Arabic mark : "<<this->marks.getArabic()<<endl;
    mytempfile<<"English mark : "<<this->marks.getEnglish()<<endl;
    mytempfile.close();
}

Mark Student::getStudentMarks()
{
    return this->marks;
}


