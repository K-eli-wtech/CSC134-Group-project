#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
	FirstName = "NULL";
	LastName = "NULL";
	SocialSecurityNumber = "NULL";
	ExamGrades[0] = 0;
	ExamGrades[1] = 0;
	ExamGrades[2] = 0;
	ExamGrades[3] = 0;
	AverageExamGrade = 0;
}

string Student::getFirstName()
{
	return FirstName;
}

void Student::setFirstName(string firstName)
{
	FirstName = firstName;
}

string Student::getLastName()
{
	return LastName;
}

void Student::setLastName(string lastName)
{
	LastName = lastName;
}

string Student::getSocialSecurityNumber()
{
	return SocialSecurityNumber;
}

void Student::setSocialSecurityNumber(string socialSecurityNumber)
{
	SocialSecurityNumber = socialSecurityNumber;
}

double Student::getExamGrade(int index)
{
	return ExamGrades[index];
}

void Student::setExamGrade(double examGrade, int index)
{
	ExamGrades[index] = examGrade;
}

void Student::setExamGrades(double firstGrade, double secondGrade, double thirdGrade, double fourthGrade)
{
	ExamGrades[0] = firstGrade;
	ExamGrades[1] = secondGrade;
	ExamGrades[2] = thirdGrade;
	ExamGrades[3] = fourthGrade;
}


double Student::getAverageExamGrade()
{
	return AverageExamGrade;
}

void Student::setAverageExamGrade(double averageExamGrade)
{
	AverageExamGrade = averageExamGrade;
}

int Student::getStudentNumber()
{
	return StudentNumber;
}

double Student::calculateAverageExamGrade()
{
	double gradeSum = 0;
	for (int i = 0; i < 4; i++)
	{
		gradeSum += getExamGrade(i);
	}
	return gradeSum / 4;
}

void Student::print()
{
	cout << "Student Name: " << getFirstName() << ' ' << getLastName() << endl;
	cout << "Social Security Number: " << getSocialSecurityNumber() << endl;
	cout << "Exam Grades: " << getExamGrade(0) << ", " << getExamGrade(1) << ", " << getExamGrade(2) << ", " << getExamGrade(3) << endl;
	cout << "Average Exam Grade: " << getAverageExamGrade() << endl;
}
