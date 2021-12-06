#pragma once
#include <iostream>
#include <string>
#include "Degree.h"
#include "Student.h"
using std::string;

//Roster header file. Declarations for all Roster class instance variables and methods. 
class Roster
{
	private:
		//Array of pointers to hold data from Student Data Table
		Student* classRosterArray[5];

		//Counter to track current index in classRosterArray (see add method in Roster.cpp)
		static int rosterIndex;

	public:
		//Constructor 
		Roster();

		//Getter for classRosterArray
		Student** getClassRosterArr();

		//Method to parse individual string from Student Data Table
		static void parse(string studentDataStr, string parsedAttributes[]);

		//Method that sets instance variables for student and updates roster
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

		//Method that removes student from the roster by student ID
		void remove(string studentID);

		//Method that prints a complete tab-separated list of student data
		void printAll();

		//Method that correctly prints a student's average number of days in the three courses
		void printAverageDaysInCourse(string studentID);

		//Method that verifies student email addresses and displays all invalid email addresses
		void printInvalidEmails();

		//Method that prints out student information for the degree program specified by the DegreeProgram enum
		void printByDegreeProgram(DegreeProgram degreeProgram);

		//Destructor
		~Roster();
};

