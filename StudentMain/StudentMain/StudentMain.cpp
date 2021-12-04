
//////////
//
// Filename: StudentMain.cpp
// Date: December 4, 2021
// Programmers: Caleb Tutor, Jacob Yates, Kaleb White, Mason Williams
// 
// Description: Creates a ClassRoom object, uses the object to read the Student objects from the input file, displays the list of Student objects sorted by AverageExamGrade, displays the list of Student objects sorted by LastName, displays the average grade of all students, and displays the number of Student objects created
//
//////////

#include <iostream>
#include <string>
#include "ClassRoom.h"
#include "Student.h"

using namespace std;

//////////
//
// Function: main
// 
// Description: uses a ClassRoom object to read input, sort, and display output
//
//////////

int main()
{
    // Creates a ClassRoom Object
    ClassRoom classRoomObject;

    // Uses the ClassRoom Object to read the Student Objects from the input file "students.txt"
    string fileName = "students.txt";
    classRoomObject.readDataFromFile(fileName);

    // Uses the ClassRoom Object to sort list of students by student average
    classRoomObject.sortOnAverage();

    // Displays the list of students by student average
    cout << "Students by Student Average:\n" << endl;
    classRoomObject.print();
    cout << '\n' << "----------------------" << "\n\n" << endl;

    // Uses the ClassRoom Object to sort list of students by student last name
    classRoomObject.sortOnLastName();

    // Displays the list of students by student last name
    cout << "Students by Student Last Name:\n" << endl;
    classRoomObject.print();
    cout << '\n' << "----------------------" << "\n\n" << endl;

    // Uses the ClassRoom Object to display the average grade of all students
    double classAverage = classRoomObject.getClassAverage();
    cout << "Class Average: " << classAverage << endl << endl;

    // Uses the ClassRoom Object to display the number of Student objects created
    int studentCount = classRoomObject.getStudentCount();
    cout << "Student Count: " << studentCount << endl << endl;
}
