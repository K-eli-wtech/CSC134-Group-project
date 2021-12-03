#include "ClassRoom.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

ClassRoom::ClassRoom()		//Default Constructor for ClassRoom Objects
{
	name = "CSC-134";
	numStudents = 0;
	studentArray = new student[23];		//replace student with name for student object
}

ClassRoom::~ClassRoom()		//Destructor for ClassRoom Objects
{
	delete[] studentArray;
}

void ClassRoom::readDataFromFile(string filename)		//Reads file data and creates student objects
{
	ifstream studentData;
	string currentLine, firstName, lastName, socialSec;
	double grade1, grade2, grade3, grade4;

	studentData.open("Students.txt");

	if (studentData.is_open())
	{
		while (!studentData.eof() && numStudents <= 24)
		{
			getline(studentData, currentLine, '\n');
            stringstream ss(currentLine);

            for (int x = 0; x < 7; x++) // there are total 7 items in one line
            {
                // storing data taken from one line offile into different variables.
                switch (x)        // position of item specifies the value of specific data member
                {
                case 0:       // 0 index is student last name
                    ss >> lastName;
                    cout << lastName << " ";
                    break;
                case 1:       // 1 index is student first name
                    ss >> firstName;
                    cout << firstName << " ";
                    break;
                case 2:       // 2 index is student social security number
                    ss >> socialSec;
                    cout << socialSec << " ";
                    break;
                case 3:       // 3 index if grade 1
                    ss >> grade1;
                    cout << grade1 << " ";
                    break;
                case 4:       // 4 index if grade 2
                    ss >> grade2;
                    cout << grade2 << " ";
                    break;
                case 5:        // 5 index if grade 3
                    ss >> grade3;
                    cout << grade3 << " ";
                    break;
                case 6:        // 6 index if grade 4
                    ss >> grade4;
                    cout << grade4 << " " << endl;
                    break;
                }
                numStudents++;
            }
		}
        studentData.close();
	}
}

void ClassRoom::sortOnAverage()     //Sorts student array by average grade from highest to lowest
{

}

void ClassRoom::sortOnLastName()        //Sorts student array alphabetically by last name
{

}

void ClassRoom::print()     //Prints results of functions
{

}

double ClassRoom::getClassAverage()     //Gets the average of entire class
{

}

int ClassRoom::getStudentCount()        //Gets the count of student objects currently created
{

}
