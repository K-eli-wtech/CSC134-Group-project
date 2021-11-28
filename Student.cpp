#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>

using namespace std;


#define MAX_STU_COUNT  24

class Student
{
    private:
        string FirstName;// (string and const)  -  (5 pts)
        string LastName; // (string and const)  - (5 pts)
        string SocialSecurity ;// (string) - (4 pts)
        double FourExam[4] ; //Grades (array of type double) - (4 pts)
        double StudentAverage;// Exam Grade (double) - (4 pts)
        //Student *next;        // It will be used for making linked list
    public:
                                  // The static data member can be taken in private area too.
        static int StudentNumber; // (int and static) - Initially set to zero. Each time a Student object is created, the  Student Number is incremented by one and when destroyed, decremented by one.  (4 pts)
        double averageExamGrade();// function to return the average Exam Grade of a student:
                                  // (Sum of Four Exam grades divided by four).
         // Setter Functions
         // Function to display associated attributes of the Student
         void setFirstName(string);
         void setLastName(string);
         void setSocialSecurity(string);
         void setFourExamGrades(double *) ; //Grades (array of type double) - (4 pts)
         void setStudentAverage(double );

         // Getters Functions
         string getFirstName();
         string getLastName();
         string getSocialSecurity();
         double* getFourExamGrades() ; //Grades (array of type double) - (4 pts)
         double getStudentAverage( );
         void show();

         // different Constructors of Student class
         Student();
         Student(string,string,string,float ,float,float,float);
         Student(const Student &);   // Copy constructor

         // Destructor
         ~Student();
         // Overloaded = operator for assigning one student object to other student object
         Student& operator = (const Student &);
};

// Definition of of static data member
int Student::StudentNumber=0; // Static data member of Student Class



// Class declaration
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



 double Student::averageExamGrade()
 {
      double total=0;
      for(int x=0;x<4;x++)
      {
          total += this->FourExam[x];  // getting total of four grade value.
      }
      return total / 4;   // getting average.
 }


 // setter functions
 void Student::setFirstName(string fname)
 {
     this->FirstName = fname ;
 }
 void Student::setLastName(string lname)
 {
     this->LastName = lname;
 }
 void Student::setSocialSecurity(string socialsec)
 {
     this->SocialSecurity = socialsec;
 }
 void Student::setFourExamGrades(double *A)
 {
      for(int x=0; x<4;x++)
      this->FourExam[x] = A[x];
 }

 void Student::setStudentAverage(double avg)
 {
     this->StudentAverage = avg;
 }

 // Getters Functions
 string Student::getFirstName()
 {
     return this->FirstName;
 }

 string Student::getLastName()
 {
     return this->LastName;
 }

 string Student::getSocialSecurity()
 {
     return this->SocialSecurity;
 }



 double* Student::getFourExamGrades()  //Grades (array of type double) - (4 pts)
 {
     return this->FourExam;
 }

 double Student::getStudentAverage( )
 {
     return this->StudentAverage;
 }



 // Constructors
 Student::Student(string fname,string lname,string social,float m1,float m2,float m3,float m4)
 {
      Student::StudentNumber += 1;
      this->FirstName = fname;
      this->LastName = lname;
      this->SocialSecurity = social;
      this->FourExam[0] = m1;
      this->FourExam[1] = m2;
      this->FourExam[2] = m3;
      this->FourExam[3] = m4;
      this->StudentAverage = this->averageExamGrade();
      //this->next= NULL;
 }

 // displaying data of student object on screen.
 void  Student::show()
 {
     cout<<"\n "<<setw(13)<<left<<this->FirstName<<"  "<<setw(13)<<left<<this->LastName<<"  "<<setw(12)<<left<<this->SocialSecurity<<"  ";
     for(int x=0;x<4;x++)
        cout<<setw(5) <<this->FourExam[x]<<"  ";
     cout<<setw(5)<<this->StudentAverage;
 }

 // Overloaded = operator
 Student& Student::operator = (const Student &obj)
 {
     this->FirstName = obj.FirstName;
     this->LastName = obj.LastName;
     this->SocialSecurity = obj.SocialSecurity;
     for(int x=0;x<4 ;x++)
        this->FourExam[x] = obj.FourExam[x];

     this->StudentAverage = obj.StudentAverage;
     return *this;
 }


 // default constructor.
 Student::Student()
 {
     this->FirstName = this->LastName = this->SocialSecurity ="";
     this->StudentAverage=0;
     for(int x=0;x<4;x++)
        this->FourExam[x] =0;
     this->StudentAverage =0;
     Student::StudentNumber += 1;
 }

 // Copy constrctor
 Student::Student(const Student &obj)
 {
     this->FirstName = obj.FirstName;
     this->LastName = obj.LastName;
     this->SocialSecurity = obj.SocialSecurity;
     for(int x=0;x<4 ;x++)
        this->FourExam[x] = obj.FourExam[x];
     //this->next= obj.next;
     this->StudentAverage = obj.StudentAverage;
     Student::StudentNumber += 1;
 }

 // destructor
 Student::~Student()
 {
     Student::StudentNumber -= 1;
 }

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
    cout<<"\n ************************************************************************************";
    cout<<"\n                                       RESULT FOR "<<this->Name;
    cout<<"\n ************************************************************************************";
    cout<<"\n First Name     Last Name  Soc.Sec.Num  Grade1   Grade2  Grade3  Grade4  Average   ";
    cout<<"\n ------------------------------------------------------------------------------------";
    for(int x=0;x<this->countStudent;x++)
    {
          this->Array[x].show();
    }

}

int ClassRoom::getStudentCount()
{
    return this->countStudent;
}


int main()
{
    cout<<fixed<<setprecision(1);

    ClassRoom classObj;   // Point 1. Create a ClassRoom Object  (3 pts)
    classObj.readDataFromFile();// point2 Use the ClassRoom Object to read the Student Objects from the input file "students.txt" (3 pts)

    cout<<"\n The data before performing different sorting: ";
    classObj.print();


    classObj.sortOnAverage();// point 3.Use  the ClassRoom Object to sort list of students by student average (3 pts)
    cout<<"\n\nThe data after sorting on descending order of average: ";
    classObj.print();    // point 4. Display the list of students by student average (3 pts)

    classObj.sortOnLastName(); // point 5. Use the ClassRoom Object to sort list of students by student last name (3 pts)
    cout<<"\n\nThe data after sorting on ascending order of last name: ";
    classObj.print(); // point 6. Display the list of students by student last name (3 pts)

    cout<<"\n ------------------------------------------------------------------------------------";
    cout<<"\n";
    cout<<"\n Statistic";
    cout<<"\n ------------------------------------------------------------------------------------";
    cout<<"\n Class Average :  "<<classObj.getClassAverage(); // point 7. Use the ClassRoom Object to display the average grade of all students. (3 pts)
    cout<<"\n Total students:  "<<classObj.getStudentCount(); // point 8. Use the ClassRoom Object to display the number of Student objects created (3 pts)
    cout<<"\n ------------------------------------------------------------------------------------";

    return(0);
}
