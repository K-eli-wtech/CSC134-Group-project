#pragma once
#include <string>
#include "Student.h"

using namespace std;

class ClassRoom
{
public:
	ClassRoom();		//Constructor
	~ClassRoom();		//Destructor
	void readDataFromFile(string filename);		//Reads file data
	void sortOnAverage();		//Sorts student ar by average grade
	void sortOnLastName();		//Sorts student array by C-String value of last name
	void print();		//Prints data
	double getClassAverage();		//Gets total class average
	int getStudentCount();		//Grabs total count of students
private:
	string name;
	Student *studentArray; 
	static int numStudents;
};
