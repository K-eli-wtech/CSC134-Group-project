
//////////
//
// Filename: Student.cpp
// Date: December 4, 2021
// Programmers: Caleb Tutor, Jacob Yates
// 
// Description: implementation for the Student class
//
//////////

#include "Student.h"
#include <iostream>

using namespace std;

int Student::StudentNumber = 0;

//////////
//
// Function: Student
// 
// Description: Default constructor, initializes variables as empty strings or 0, increments StudentNumber
//
//////////

Student::Student()
{
	setFirstName("");
	setLastName("");
	setSocialSecurityNumber("");
	setExamGrades(0, 0, 0, 0);
	setAverageExamGrade(calculateAverageExamGrade());
	StudentNumber++;
}

//////////
//
// Function: Student
// 
// Description: Constructor with parameters, initializes variables with the parameters, increments StudentNumber
// 
// Parameters:
//  firstName : string first name of the student
//  lastName : string last name of the student
//  socialSecurityNumber : string social security number of the student
//  firstGrade : double student's first exam grade
//  secondGrade : double student's second exam grade
//  thirdGrade : double student's third exam grade
//  fourthGrade : double student's fourth exam grade
//
//////////

Student::Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade)
{
	setFirstName(firstName);
	setLastName(lastName);
	setSocialSecurityNumber(socialSecurityNumber);
	setExamGrades(firstGrade, secondGrade, thirdGrade, fourthGrade);
	setAverageExamGrade(calculateAverageExamGrade());
	StudentNumber++;
}

//////////
//
// Function: ~Student
// 
// Description: Deconstructor, decrements StudentNumber
//
//////////

Student::~Student()
{
	StudentNumber--;
}

//////////
//
// Function: getFirstName
// 
// Description: returns the student's first name
// 
// Returns:
//  string : the student's first name
//
//////////

string Student::getFirstName()
{
	return FirstName;
}

//////////
//
// Function: setFirstName
// 
// Description: sets the student's first name
// 
// Parameters:
//  firstName : string that the student's first name is set to
//
//////////

void Student::setFirstName(string firstName)
{
	FirstName = firstName;
}

//////////
//
// Function: getLastName
// 
// Description: returns the student's last name
// 
// Returns:
//  string : the student's last name
//
//////////

string Student::getLastName()
{
	return LastName;
}

//////////
//
// Function: setLastName
// 
// Description: sets the student's last name
// 
// Parameters:
//  lastName : string that the student's last name is set to
//
//////////

void Student::setLastName(string lastName)
{
	LastName = lastName;
}

//////////
//
// Function: getSocialSecurityNumber
// 
// Description: returns the student's social security number
// 
// Returns:
//  string : the student's social security number
//
//////////

string Student::getSocialSecurityNumber()
{
	return SocialSecurityNumber;
}

//////////
//
// Function: setSocialSecurityNumber
// 
// Description: sets the student's social security number
// 
// Parameters:
//  socialSecurityNumber : string that the student's social security number is set to
//
//////////

void Student::setSocialSecurityNumber(string socialSecurityNumber)
{
	SocialSecurityNumber = socialSecurityNumber;
}

//////////
//
// Function: getExamGrade
// 
// Description: returns one of the student's exam grades
// 
// Parameters: 
//  index : int index of the exam grade to get in ExamGrades
// 
// Returns:
//  double : exam grade at ExamGrades[index]
//
//////////

double Student::getExamGrade(int index)
{
	return ExamGrades[index];
}

//////////
//
// Function: setExamGrade
// 
// Description: sets one of the student's exam grades
// 
// Parameters:
//  examGrade : double value that the exam grade is going to be set to
//  index : int index of the exam grade to replace in ExamGrades
//
//////////

void Student::setExamGrade(double examGrade, int index)
{
	ExamGrades[index] = examGrade;
}

//////////
//
// Function: setExamGrades
// 
// Description: sets all of the student's exam grades
// 
// Parameters:
//  firstGrade : double first exam grade value
//  secondGrade : double second exam grade value
//  thirdGrade : double third exam grade value
//  fourthGrade : double fourth exam grade value
//
//////////

void Student::setExamGrades(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade)
{
	ExamGrades[0] = firstGrade;
	ExamGrades[1] = secondGrade;
	ExamGrades[2] = thirdGrade;
	ExamGrades[3] = fourthGrade;
}

//////////
//
// Function: getAverageExamGrade
// 
// Description: returns the student's average exam grade
// 
// Returns:
//  double : the student's average exam grade
//
//////////

double Student::getAverageExamGrade()
{
	return AverageExamGrade;
}

//////////
//
// Function: setAverageExamGrade
// 
// Description: sets the student's average exam grade
// 
// Parameters:
//  averageExamGrade : double the the average exam grade is set to
//
//////////

void Student::setAverageExamGrade(double averageExamGrade)
{
	AverageExamGrade = averageExamGrade;
}

//////////
//
// Function: calculateAverageExamGrade
// 
// Description: calculates the student's average exam grade
// 
// Returns:
//  double : average value of the exam grades in ExamGrades
//
//////////

double Student::calculateAverageExamGrade()
{
	double gradeSum = 0;
	for (int i = 0; i < 4; i++)
	{
		gradeSum += getExamGrade(i);
	}
	return gradeSum / 4;
}

//////////
//
// Function: getStudentNumber
// 
// Description: returns the number of students
// 
// Returns:
//  int : the number of students
//
//////////

int Student::getStudentNumber()
{
	return StudentNumber;
}

//////////
//
// Function: print
// 
// Description: prints the student's full name, social security number, exam grades, and average exam grade
//
//////////

void Student::print()
{
	cout << "Student Name: " << getFirstName() << ' ' << getLastName() << endl;
	cout << "Social Security Number: " << getSocialSecurityNumber() << endl;
	cout << "Exam Grades: " << getExamGrade(0) << ", " << getExamGrade(1) << ", " << getExamGrade(2) << ", " << getExamGrade(3) << endl;
	cout << "Average Exam Grade: " << getAverageExamGrade() << '\n' << endl;
}
