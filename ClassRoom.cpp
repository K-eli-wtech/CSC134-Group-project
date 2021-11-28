#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include "Student.cpp"

using namespace std;

class ClassRoom
{
        string Name;
        int countStudent;
        Student *Array; // Dynamic array for student, max is MAX_STU_COUNT
    public:
        ClassRoom();
        ~ClassRoom();
        void readDataFromFile(string filename="student.dat");
        void sortOnAverage();
        void sortOnLastName();
        double getClassAverage();
        void print();
        int getStudentCount();

};


/** ClassClassroom Members : */
ClassRoom::ClassRoom()
{
    this->Name="CSC134";
    this->countStudent=0;
    Array = new Student[MAX_STU_COUNT];      // 24 elements
}

ClassRoom::~ClassRoom()
{

        delete [ ] Array;
}

void ClassRoom::readDataFromFile(string filename)
{
    ifstream file;
    string line;
    string fnm,lnm,social;  // to keep student first name , last name and social security num
    double m1,m2,m3,m4;      // to keep four grade values

    file.open("Students.txt",ios::in);
    this->countStudent = 0 ;

    if(file.is_open())
    {
        while(file.eof()==false)
        {
             getline(file,line,'\n');
             // cout<<"\n"<<line;
             stringstream ss(line);

             for(int x=0;x<7;x++) // there are total 7 items in one line
             {
                 // storing data taken from one line offile into different variables.
                 switch(x)        // position of item specifies the value of specific data member
                 {
                    case 0:       // 0 index is student first name
                        ss>> fnm;
                        break;
                    case 1:       // 1 index is student last name
                        ss >> lnm;
                        break;
                    case 2:       // 2 index is student social security number
                        ss >> social;
                        break;
                    case 3:       // 3 index if grade 1
                        ss >> m1;
                        break;
                    case 4:       // 4 index if grade 2
                        ss >> m2;
                        break;
                    case 5:        // 5 index if grade 3
                        ss >> m3;
                        break;
                    case 6:        // 6 index if grade 4
                        ss >> m4;
                        break;
                 }
             }

             // Below line makes object of student using the vales taken in different variables.
             this->Array[this->countStudent] = Student(fnm,lnm,social,m1,m2,m3,m4);
             this->countStudent += 1;   // increasing the count of student as 1 student is added in the array.
        }
        file.close();   // closing file.
    }
}

void ClassRoom::sortOnAverage()
{
    int fix,compare;
    Student pos;
    // using insertion sort //  DESCENDING ORDER ON AVERAGE , TOPPERS ARE AT TOP
    for(fix=1;fix<this->countStudent;fix++)
    {
        pos = this->Array[fix];
        for(compare=fix -1 ; compare>=0 && this->Array[compare].getStudentAverage()<pos.getStudentAverage(); compare--)
        {
            this->Array[compare+1] = this->Array[compare];
        }
        this->Array[compare+1] = pos;
    }
}

void ClassRoom::sortOnLastName()
{
    int fix,compare;
    Student pos;
    // using insertion sort //  ASCENDING ORDER ON LASTNAME , TOPPERS ARE AT TOP
    for(fix=1;fix<this->countStudent;fix++)
    {
        pos = this->Array[fix];
        for(compare=fix -1 ; compare>=0 && this->Array[compare].getLastName()>pos.getLastName(); compare--)
        {
            this->Array[compare+1] = this->Array[compare];
        }
        this->Array[compare+1] = pos;
    }
}

double ClassRoom::getClassAverage()
{
     double total=0,average=0;
     double * ar;
     for(int x =0; x< this->countStudent;x++)
     {
        total = total + this->Array[x].getStudentAverage();


     }
     average = total/ this->countStudent;
     return average;
}

void ClassRoom::print()
{
    cout << "\n ************************************************************************************";
    cout << "\n                                       RESULT FOR "<<this->Name;
    cout << "\n ************************************************************************************";
    cout << "\n First Name     Last Name  Soc.Sec.Num  Grade1   Grade2  Grade3  Grade4  Average   ";
    cout << "\n ------------------------------------------------------------------------------------";
    for(int x=0;x<this->countStudent;x++)
    {
          this->Array[x].show();
    }

}

int ClassRoom::getStudentCount()
{
    return this->countStudent;
}
