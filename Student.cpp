#include "Student.h"
#include <iostream>
#include <string>
#include "Degree.h"
using std::cout;

//Student C++ file. Definitions of Student class methods from header file.

//Constructor for all parameters
Student::Student(string s, string f, string l, string e, int a, int c[], DegreeProgram d)
{
	studentID = s;
	firstName = f;
	lastName = l;
	emailAddress = e;
	age = a;
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = c[i];
	}
	degreeProgram = d;
}

//Getters and setters for all instance variables
string Student::getStudentID()
{
	return studentID;
}
void Student::setStudentID(string s)
{
	studentID = s;
}

string Student::getFirstName()
{
	return firstName;
}
void Student::setFirstName(string f)
{
	firstName = f;
}

string Student::getLastName()
{
	return lastName;
}
void Student::setLastName(string l)
{
	lastName = l;
}

string Student::getEmailAddress()
{
	return emailAddress;
}
void Student::setEmailAddress(string e)
{
	emailAddress = e;
}

int Student::getAge()
{
	return age;
}
void Student::setAge(int a)
{
	age = a;
}

int* Student::getDaysInCourse()
{
	return daysInCourse;
}
void Student::setDaysInCourse(int c[3])
{
	for (int i=0; i < 3; i++)
	{
		daysInCourse[i] = c[i];
	}
}

DegreeProgram Student::getDegreeProgram()
{
	return degreeProgram;
}
void Student::setDegreeProgram(DegreeProgram d)
{
	degreeProgram = d;
}

//Print method to print student data
void Student::print()
{
	cout << "Student ID: " << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Email Address: " << emailAddress << "\t";
	cout << "Age: " << age << "\t";

	//Print days in course
	cout << "Days in course: {";
	for (int i = 0; i < 2; i++)
	{
		cout << daysInCourse[i] << ", ";
	}
	cout << daysInCourse[2];
	cout << "}\t";

	//Print Degree Program
	string degreeProgramStr;
	if (degreeProgram == DegreeProgram::SECURITY) {
		degreeProgramStr = "Security";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		degreeProgramStr = "Network";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		degreeProgramStr = "Software";
	}
	cout << "Degree program: " << degreeProgramStr << "\t";
	cout << "\n";
}