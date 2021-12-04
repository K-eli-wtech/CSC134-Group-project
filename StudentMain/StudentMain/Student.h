#pragma once
#include <string>

using namespace std;

class Student
{
public:
	static int StudentNumber;
	string getFirstName();
	string getLastName();
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
	Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
private:
	const string FirstName;
	const string LastName;
	string SocialSecurityNumber;
	double ExamGrades[4];
	double AverageExamGrade;
};
