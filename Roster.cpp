#include <iostream>
#include <string>
#include "Roster.h"
#include "Student.h"
using std::cout;
using std::string;

//Roster C++ file. Definitions of Roster class methods from header file.

//Roster Index initialized
int Roster::rosterIndex = 0;

//Constructor 
Roster::Roster()
{
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i] = nullptr;
	}
}

//Getter for classRosterArray
Student** Roster::getClassRosterArr()
{
	return classRosterArray;
}

//Method to parse individual string from Student Data Table
void Roster::parse(string studentDataStr, string parsedAttributes[9])
{
	int length = studentDataStr.length();
	int PAIdx = 0;
	for (int i = 0; i < length; i++)
	{
		if (studentDataStr[i] == ',')
		{
			PAIdx++;
			continue;
		}
		parsedAttributes[PAIdx] += studentDataStr[i];
	}
};

//Method that sets instance variables for student and updates roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
	rosterIndex += 1;
};

//Method that removes student from the roster by student ID
void Roster::remove(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			Student currentStudent = *classRosterArray[i];
			if (currentStudent.getStudentID() == studentID) 
			{
				classRosterArray[i] = nullptr;
				return;
			}
		}
		else
		{
			continue;
		}
		
	}
	cout << "Such a student with this ID was not found.\n";

};

//Method that prints a complete tab-separated list of student data
void Roster::printAll()
{
	cout << "Roster:\n";
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != nullptr)
		{
			Student currentStudent = *classRosterArray[i];
			currentStudent.print();
		}
	}
	cout << "\n";
};

//Method that correctly prints a student's average number of days in the three courses
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		Student currentStudent = *classRosterArray[i];
		if (currentStudent.getStudentID() == studentID) {
			int* daysInCourse = currentStudent.getDaysInCourse();
			int sumOfDays = *(daysInCourse)+*(daysInCourse + 1) + *(daysInCourse + 2);
			cout << "Average for " << currentStudent.getFirstName() << " " << currentStudent.getLastName() << ": " << (float) sumOfDays / 3 << "\n";
			return;
		}
	}
	cout << "Such a student with this ID was not found.\n";

};

//Method that verifies student email addresses and displays all invalid email addresses
void Roster::printInvalidEmails()
{
	cout << "Invalid Emails: \n";
	for (int i = 0; i < 5; i++)
	{
		Student currentStudent = *classRosterArray[i];
		string currentEmail = currentStudent.getEmailAddress();
		int length = currentEmail.length();
		bool containsPeriod = false;
		bool containsAt = false;
		bool containsSpace = false;
		for (int j = 0; j < length; j++)
		{
			if (currentEmail[j] == '.') 
			{
				containsPeriod = true;
			} 
			if (currentEmail[j] == '@') 
			{
				containsAt = true;
			}
			if (currentEmail[j] == ' ')
			{
				containsSpace = true;
			}
		}
		if (!(containsPeriod && containsAt && !containsSpace))
		{
			cout << currentEmail << "\n";
		}
	}
	cout << "\n";
};

//Method that prints out student information for the degree program specified by the DegreeProgram enum
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	cout << "Print by Degree Program: \n";
	for (int i = 0; i < 5; i++)
	{
		Student currentStudent = *classRosterArray[i];
		DegreeProgram currentDegreeProgram = currentStudent.getDegreeProgram();
		if (currentDegreeProgram == degreeProgram)
		{
			currentStudent.print();
		}
	}
	cout << "\n";
};

//Default destructor
Roster::~Roster() {};