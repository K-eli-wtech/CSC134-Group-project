
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
	Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
	~Student();
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
	double calculateAverageExamGrade();
	int getStudentNumber();
	void print();
private:
	static int StudentNumber;
	string FirstName;
	string LastName;
	string SocialSecurityNumber;
	double ExamGrades[4];
	double AverageExamGrade;
};
