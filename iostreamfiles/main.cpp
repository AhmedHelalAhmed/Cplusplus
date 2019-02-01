#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <fstream>
using namespace std;


void generate_fake_student_data();
template <class T>
void store_data_info_file(T data);
string generate_student_name();

static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;


int main()
{
bool again =true;
while(again)
{
    generate_fake_student_data();
    cout<< "success"<<endl;
    cout<<"for again press 1 : ";
    cin>>again;
}


    return 0;
}





string generate_student_name()
{

    char name[5];
    int z;
    for(z=0; z < 5; z++)
    name[z]= alphanum[rand() % stringLength];
    name[z] = '\0';

    return name;
}



void generate_fake_student_data()
{
    double arabic = 0;
    double english = 0;
    double math = 0;
    string studen_name="";

    srand(time(0));
    studen_name = generate_student_name();
    arabic =  rand() % 100;
    english = rand() % 100;
    math =  rand() % 100;

    store_data_info_file(studen_name);
    store_data_info_file("\t");
    store_data_info_file(arabic);
    store_data_info_file("\t");
    store_data_info_file(english);
    store_data_info_file("\t");
    store_data_info_file(math);
    store_data_info_file("\n");


}




// ToDo make the function template
template <class T>
void store_data_info_file(T data)
{
    ofstream myfile;
    myfile.open ("students.txt", std::ios_base::app);
    myfile << data;
    myfile.close();
}
