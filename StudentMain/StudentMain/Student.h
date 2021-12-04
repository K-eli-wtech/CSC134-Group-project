
//////////
//
// Filename: Student.h
// Date: December 4, 2021
// Programmers: Caleb Tutor, Jacob Yates
// 
// Description: interface for the Student class
//
//////////

#pragma once
#include <string>

using namespace std;

//////////
//
// Class: Student
// 
// Description: Contains information about a single student and can display that information
// 
// Data Members:
//  StudentNumber
//  FirstName
//  LastName
//  SocialSecurityNumber
//  ExamGrades
//  AverageExamGrade
// 
// Member Functions:
//  Student (2)
//  ~Student
//  getFirstName
//  setFirstName
//  getLastName
//  setLastName
//  getSocialSecurityNumber
//  setSocialSecurityNumber
//  getExamGrade
//  setExamGrade
//  setExamGrades
//  getAverageExamGrade
//  setAverageExamGrade
//  calculateAverageExamGrade
//  getStudentNumber
//  print
//
//////////

class Student
{
public:
	Student();
	// Default Constructor
	// Initializes variables as empty strings or 0
	// Increments StudentNumber
	// Postcondition:
	//  FirstName = ""
	//  LastName = ""
	//  SocialSecurityNumber = ""
	//  ExamGrades = { 0, 0, 0, 0 }
	//  AverageExamGrade = 0
	//  StudentNumber += 1

	Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
	// Constructor with parameters
	// Initializes variables with the parameters
	// Increments StudentNumber
	// Postcondition:
	//  FirstName = firstName
	//  LastName = lastName
	//  SocialSecurityNumber = socialSecurityNumber
	//  ExamGrades = { firstGrade, secondGrade, thirdGrade, fourthGrade }
	//  AverageExamGrade is calculated
	//  StudentNumber += 1

	~Student();
	// Deconstructor
	// Decrements StudentNumber
	// Postcondition:
	//  StudentNumber -= 1

	string getFirstName();
	// Function that returns the student's first name
	// Postcondition: 
	//  returns FirstName
	
	void setFirstName(string firstName);
	// Function that sets the student's first name
	// Postcondition:
	//  FirstName = firstName
	
	string getLastName();
	// Function that returns the student's last name
	// Postcondition:
	//  returns LastName
	
	void setLastName(string lastName);
	// Function that sets the student's last name
	// Postcondition:
	//  LastName = lastName
	
	string getSocialSecurityNumber();
	// Function that returns the student's social security number
	// Postcondition:
	//  returns SocialSecurityNumber
	
	void setSocialSecurityNumber(string socialSecurityNumber);
	// Function that sets the student's social security number
	// Postcondition:
	//  SocialSecurityNumber = socialSecurityNumber
	
	double getExamGrade(int index);
	// Function that returns one of the student's exam grades
	// Postcondition:
	//  returns ExamGrades[index]
	
	void setExamGrade(double examGrade, int index);
	// Function that sets one of the student's exam grades
	// Postcondition:
	//  ExamGrades[index] = examGrade
	
	void setExamGrades(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
	// Function that sets all of the student's exam grades
	// Postcondition:
	//  ExamGrades = { firstGrade, secondGrade, thirdGrade, fourthGrade }
	
	double getAverageExamGrade();
	// Function that returns the student's average exam grade
	// Postcondition:
	//  returns AverageExamGrade
	
	void setAverageExamGrade(double averageExamGrade);
	// Function that sets the student's average exam grade
	// Postcondition:
	//  AverageExamGrade = averageExamGrade
	
	double calculateAverageExamGrade();
	// Function that calculates the student's average exam grade
	// Postcondition:
	//  returns the sum of ExamGrades divided by 4
	
	int getStudentNumber();
	// Function that returns the number of students
	// Postcondition:
	//  returns StudentNumber
	
	void print();
	// Function that prints the student's full name, social security number, exam grades, and average exam grade
	// Postcondition:
	//  The information is printed in the format
	//  Student Name: FirstName LastName
	//  Social Security Number: SocialSecurityNumber
	//  Exam Grades: ExamGrades
	//  Average Exam Grade: AverageExamGrade

private:
	static int StudentNumber;
	// static variable the stores the number of students

	string FirstName;
	// variable that stores the student's first name

	string LastName;
	// variable that stores the student's last name

	string SocialSecurityNumber;
	// variable that stores the student's social security number

	double ExamGrades[4];
	// variable that stores all 4 of the student's exam grades

	double AverageExamGrade;
	// variable that stores the student's average exam grade
};
