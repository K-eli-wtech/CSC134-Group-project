#include <iostream>
#include "ClassRoom.h"
#include "Student.h"
#include <string>

using namespace std;

int main()
{
    // Create a ClassRoom Object
    ClassRoom classRoomObject;

    // Use the ClassRoom Object to read the Student Objects from the input file "students.txt"
    string fileName = "students.txt";
    classRoomObject.readDataFromFile(fileName);

    // Use the ClassRoom Object to sort list of students by student average
    classRoomObject.sortOnAverage();

    // Display the list of students by student average
    cout << "Students by Student Average" << endl;
    classRoomObject.print();

    // Use the ClassRoom Object to sort list of students by student last name
    classRoomObject.sortOnLastName();

    // Display the list of students by student last name
    cout << "Students by Student Last Name" << end;
    classRoomObject.print();

    // Use the ClassRoom Object to display the average grade of all students
    double classAverage = classRoomObject.getClassAverage();
    cout << "Class Average: " << classAverage << endl;

    // Use the ClassRoom Object to display the number of Student objects created
    int studentCount = classRoomObject.getStudentCount();
    cout << "Student Count: " << studentCount << endl;
}
