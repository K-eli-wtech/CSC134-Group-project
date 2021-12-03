#pragma once
#include <string>

class Student
{
public:
	std::string getFirstName();
	void setFirstName(std::string firstName);
	std::string getLastName();
	void setLastName(std::string lastName);
	std::string getSocialSecurityNumber();
	void setSocialSecurityNumber(std::string socialSecurityNumber);
	double getExamGrade(int index);
	void setExamGrade(double examGrade, int index);
	void setExamGrades(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade);
	double getAverageExamGrade();
	void setAverageExamGrade(double averageExamGrade);
	int getStudentNumber();
	double calculateAverageExamGrade();
	void print();
	Student();
private:
	std::string FirstName;
	std::string LastName;
	std::string SocialSecurityNumber;
	double ExamGrades[4];
	double AverageExamGrade;
	int StudentNumber;
};
