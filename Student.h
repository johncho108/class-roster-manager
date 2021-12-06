#pragma once
#include <iostream>
#include <string>
#include "Degree.h"
using std::cout;
using std::string;

//Student header file. Declarations for all Student class instance variables and methods. 
class Student
{
	private:
		//Instance variables
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		int daysInCourse[3];
		DegreeProgram degreeProgram;

	public:
		//Constructor for all parameters
		Student(string s, string f, string l, string e, int a, int c[], DegreeProgram d);

		//Getters and setters for all instance variables
		string getStudentID();
		void setStudentID(string s);
		string getFirstName();
		void setFirstName(string f);
		string getLastName();
		void setLastName(string l);
		string getEmailAddress();
		void setEmailAddress(string e);
		int getAge();
		void setAge(int a);
		int* getDaysInCourse();
		void setDaysInCourse(int c[]);
		DegreeProgram getDegreeProgram();
		void setDegreeProgram(DegreeProgram d);

		//Print method to print student data
		void print();
};

