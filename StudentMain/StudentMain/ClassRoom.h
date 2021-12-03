#pragma once
#include <string>
#include "Student.h"

using namespace std;

class ClassRoom
{
public:
	ClassRoom(); //Constructor
	~ClassRoom(); //Destructor
	void readDataFromFile(string filename);
	void sortOnAverage();
	void sortOnLastName();
	void print();
	double getClassAverage();
	int getStudentCount();
private:
	string name;
	int numStudents;
	Student* studentArray; 
};

