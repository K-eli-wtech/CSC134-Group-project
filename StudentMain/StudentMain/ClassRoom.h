#pragma once
#include <string>

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
	student* studentArray; //replace student with name for student object
};

