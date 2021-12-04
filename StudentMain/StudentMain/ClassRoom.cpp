#include "ClassRoom.h"
#include "Student.h"
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int ClassRoom::numStudents = 0;

ClassRoom::ClassRoom()		//Default Constructor for ClassRoom Objects
{
	name = "CSC-134";
	studentArray = new Student[24];
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
		while (!studentData.eof() && numStudents < 24)
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
                    break;
                case 1:       // 1 index is student first name
                    ss >> firstName;
                    break;
                case 2:       // 2 index is student social security number
                    ss >> socialSec;
                    break;
                case 3:       // 3 index if grade 1
                    ss >> grade1;
                    break;
                case 4:       // 4 index if grade 2
                    ss >> grade2;
                    break;
                case 5:        // 5 index if grade 3
                    ss >> grade3;
                    break;
                case 6:        // 6 index if grade 4
                    ss >> grade4;
                    break;
                }
            }
            Student studentObj(firstName, lastName, socialSec, grade1, grade2, grade3, grade4);
            studentObj.setAverageExamGrade(studentObj.calculateAverageExamGrade());
            studentArray[numStudents] = studentObj;
            numStudents++;
		}
        studentData.close();
	}
}

void ClassRoom::sortOnAverage()
{
    int index;
    int smallestIndex;
    int location;
    int temp;

    for (index = 0; index <= numStudents; index++)
    {
        smallestIndex = index;
        for (location = index + 1; location <= numStudents; location++)
        {
            if (studentArray[location].getAverageExamGrade() < studentArray[smallestIndex].getAverageExamGrade())
            {
                smallestIndex = location;
            }
        }
        temp = studentArray[smallestIndex].getAverageExamGrade();
        studentArray[smallestIndex].setAverageExamGrade(studentArray[index].getAverageExamGrade());
        studentArray[index].setAverageExamGrade(temp);
    }

    for (int i = 0; i < numStudents; i++)
    {
        studentArray[i].print();
    }
}
