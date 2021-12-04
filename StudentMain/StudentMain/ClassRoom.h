
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
	ClassRoom();
	// Default Constructor
	// Initializes the classroom name and array of Students
	// Postcondition:
	//  Name = "CSC-134"
	//  StudentArray = new Student[24]
	
	~ClassRoom();
	// Deconstructor
	// deletes StudentArray
	// Postcondition:
	//  delete[] StudentArray
	
	double getClassAverage();
	// Function that returns the total class average
	// Postcondition:
	//  returns the sum of all Student.AverageExamGrade in StudentArray divided by StudentCount
	
	int getStudentCount();
	// Function that returns the total number of students
	// Postcondition:
	//  returns StudentCount
	
	void incrementStudentCount();
	// Function that increments StudentCount
	// Postcondition:
	//  StudentCount += 1
	
	void readDataFromFile(string filename);
	// Function that stores the data from the file filename into Student objects in StudentArray
	// Postcondition:
	//  StudentArray gains Student objects per line of filename, up to a maximum of 24
	
	void sortOnAverage();
	// Function that sorts the students in StudentArray by their average grade
	// Postcondition:
	//  StudentArray becomes sorted based on the values of Student.AverageExamGrade
	
	void sortOnLastName();
	// Function that sorts the students in StudentArray by their last name
	// Postcondition:
	//  StudentArray becomes sorted based on the values of Student.LastName
	
	void print();
	// Function that prints the information about the students using Student.print()
	// Postcondition:
	//  for each Student in StudentArray
	//  Student.print()
	
private:
	static int StudentCount;
	// static variable that stores the number of students

	string Name;
	// variable that stores the name of the classroom

	Student *StudentArray;
	// array that stores pointers to Student objects
};
