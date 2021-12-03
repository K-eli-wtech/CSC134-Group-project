#pragma once
#include <string>

class Student
{
private:
	string FirstName;
	string LastName;
	string SocialSecurityNumber;
	double ExamGrades[4];
	double AverageExamGrade;
	static int StudentNumber;
public:
	string getFirstName();
	void setFirstName(string firstName);
	string getLastName();
	void setLastName(string lastName);
	string getSocialSecurityNumber();
	void setSocialSecurityNumber(string socialSecurityNumber);
	double getExamGrade(int index);
	double setExamGrade(double examGrade, int index);
	void setExamGrades(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
	double getAverageExamGrade();
	void setAverageExamGrade(double averageExamGrade);
	int getStudentNumber();
	double calculateAverageExamGrade();
	void print();
};
