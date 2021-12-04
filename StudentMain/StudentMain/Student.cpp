#include "Student.h"
#include <iostream>

using namespace std;

int Student::StudentNumber = 0;

Student::Student() : FirstName(""), LastName("")
{
	setSocialSecurityNumber("");
	setExamGrades(0, 0, 0, 0);
	setAverageExamGrade(calculateAverageExamGrade());
	StudentNumber++;
}

Student::Student(string firstName, string lastName, string socialSecurityNumber, double firstGrade, double secondGrade, double thirdGrade, double fourthGrade) : FirstName(firstName), LastName(lastName)
{
	setSocialSecurityNumber(socialSecurityNumber);
	setExamGrades(firstGrade, secondGrade, thirdGrade, fourthGrade);
	setAverageExamGrade(calculateAverageExamGrade());
	StudentNumber++;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
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
