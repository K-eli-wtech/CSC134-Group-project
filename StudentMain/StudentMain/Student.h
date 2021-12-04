#pragma once
#include <string>

using namespace std;

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
	Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
private:
	string FirstName;
	string LastName;
	string SocialSecurityNumber;
	double ExamGrades[4];
	double AverageExamGrade;
};
