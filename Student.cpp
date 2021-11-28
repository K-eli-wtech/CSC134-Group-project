#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<iomanip>
#include "ClassRoom.cpp"

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
