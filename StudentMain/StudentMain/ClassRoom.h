
//////////
//
// Filename: ClassRoom.h
// Date: December 4, 2021
// Programmers: Jacob Yates, Caleb Tutor
// 
// Description: interface for the ClassRoom class
//
//////////

#pragma once
#include <string>
#include "Student.h"

using namespace std;

//////////
//
// Class: ClassRoom
// 
// Description: Contains information about up to 24 Students, can sort and display that information
// 
// Data Members:
//  StudentCount
//  Name
//  StudentArray
// 
// Member Functions:
//  ClassRoom
//  ~ClassRoom
//  getClassAverage
//  getStudentCount
//  incrementStudentCount
//  readDataFromFile
//  sortOnAverage
//  sortOnLastName
//  print
//
//////////

class ClassRoom
{
public:
	ClassRoom();		//Constructor
	~ClassRoom();		//Destructor
	double getClassAverage();		//Gets total class average
	int getStudentCount();		//Grabs total count of students
	void incrementStudentCount();
	void readDataFromFile(string filename);		//Reads file data
	void sortOnAverage();		//Sorts student ar by average grade
	void sortOnLastName();		//Sorts student array by C-String value of last name
	void print();		//Prints data
private:
	static int StudentCount;
	string Name;
	Student *StudentArray;
};
