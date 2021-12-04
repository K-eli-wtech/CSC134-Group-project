
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
//  FirstName
//  LastName
//  SocialSecurityNumber
//  ExamGrades
//  AverageExamGrade
//  StudentNumber
// 
// Member Functions:
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
//  Student (2)
//  ~Student
//
//////////

class Student
{
public:
	static int StudentNumber;
	string getFirstName();
	void setFirstName(string firstName);
	string getLastName();
	void setLastName(string lastName);
	string getSocialSecurityNumber();
	void setSocialSecurityNumber(string socialSecurityNumber);
	double getExamGrade(int index);
	void setExamGrade(double examGrade, int index);
	void setExamGrades(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
	double getAverageExamGrade();
	void setAverageExamGrade(double averageExamGrade);
	int getStudentNumber();
	double calculateAverageExamGrade();
	void print();
	Student();
	~Student();
	Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
private:
	string FirstName;
	string LastName;
	string SocialSecurityNumber;
	double ExamGrades[4];
	double AverageExamGrade;
};
