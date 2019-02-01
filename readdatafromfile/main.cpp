#include <iostream>
#include <fstream>
#include <vector>
#include "Mark.h"
#include "Student.h"
#include <cmath>
using namespace std;


/*
1- structure student class and marks class
2- make array of student objects
3- read data from file
4- get information from data
- max mark for every subject and the student name
- mini mark for every subject and the student name
- how many student pass
- how many student fail
- the precentage of success
- the precentage of fail
*/
ofstream myinfofile; //public variable for output data into file (output stream)

Student* read_student_data_from_file(int &n)
{
    string line;
    char name[30];
    int math, arabic, english;
    ifstream myfile ("students.txt");
    ifstream myfileforcount ("students.txt");
    Student* students;

    //n is number of students
    int i=0;


    if (myfileforcount.is_open())
    {

        while (getline (myfileforcount,line) )
        {
            n++;
        }
        // cout<<"You have "<<n<<"students"<<endl;
        myfileforcount.close();
    }
    else
    {
        cout << "Unable to open file";
    }

    // allocate memory for students
    students= new Student[n];// pointer of student type deal with it as array



    if (myfile.is_open())
    {

        myfile >> name>> math>> arabic>>english;
        while (getline (myfile,line) )
        {

            Mark student_marks(arabic,math,english);
            Student student(name,student_marks);

            students[i]=student;
            myfile >> name>> math>> arabic>>english;
            i++;
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }


return students;


}

// for read student full data
void read_full_student_data()
{
    ifstream mytempfile ("temp.txt");
    string line;
    while (getline (mytempfile,line) )
    {
        myinfofile<<line<<endl;
    }
    mytempfile.close();
    remove("temp.txt");//delete the file
}

int main()
{
    Student * list_of_students;
    int n=0;
    list_of_students = read_student_data_from_file(n);

    int maxMath=list_of_students[0].getStudentMarks().getMath();
    int student_top_in_math=0;
    int maxArabic=list_of_students[0].getStudentMarks().getArabic();
    int student_top_in_Arabic=0;
    int maxEnglish=list_of_students[0].getStudentMarks().getEnglish();
    int student_top_in_English=0;

    int success_students_count=0;

    for(int j=0;j<n;j++)
    {
        //list_of_students[j].printStudentData();// pointer as array


        int current_math=list_of_students[j].getStudentMarks().getMath();
        int current_arabic=list_of_students[j].getStudentMarks().getArabic();
        int current_english=list_of_students[j].getStudentMarks().getEnglish();


        if(current_math>maxMath)
        {
            maxMath=current_math;
            student_top_in_math=j;

        }

        if(current_arabic>maxArabic)
        {
            maxArabic=current_arabic;
            student_top_in_Arabic=j;

        }

        if(current_english>maxEnglish)
        {
            maxEnglish=current_english;
            student_top_in_English=j;

        }

        if(list_of_students[j].getStudentMarks().isPass())
        {
            success_students_count++;
        }

    }



    myinfofile.open ("info.txt", std::ios_base::out);
    myinfofile<<"max mark in math "<<maxMath<<endl;
    myinfofile<<"the top student in math is "<<endl;

    list_of_students[student_top_in_math].printStudentData();
    read_full_student_data();

    myinfofile<<"max mark in english "<<maxEnglish<<endl;
    myinfofile<<"the top student in english is "<<endl;
    list_of_students[student_top_in_English].printStudentData();
    read_full_student_data();

    myinfofile<<"max mark in arabic "<<maxArabic<<endl;
    myinfofile<<"the top student in arabic is "<<endl;
    list_of_students[student_top_in_Arabic].printStudentData();
    read_full_student_data();

    myinfofile<<"number of success : "<<success_students_count<<endl;

    myinfofile<<"number of fail : "<<n-success_students_count<<endl;

    myinfofile<<"precentage of success : "<<round((success_students_count*1.0/n)*100)<<endl;

    myinfofile<<"precentage of fail : "<<round(((n-success_students_count)*1.0/n)*100)<<endl;


    myinfofile.close();

    delete [] list_of_students;
    return 0;
}
