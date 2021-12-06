#include <iostream>
#include <string>
#include "Roster.h"
#include "Student.h"
#include "Degree.h"
using std::string;
using std::cout;
using std::stoi;

int main()
{
	//Print my information
	cout << "COURSE TITLE: SCRIPTING AND PROGRAMMING - APPLICATIONS - C867\n";
	cout << "PROGRAMMING LANGUAGE USED: C++\n";
	cout << "WGU STUDENT ID: 009749143\n";
	cout << "NAME: John Cho\n";
	cout << "\n";

	//Create roster
	Roster classRoster;

	//Student Data Table
	const string studentDataTable[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,John,Cho-Fragoso,johncho108@wgu.edu,31,10,21,12,SOFTWARE"
	};

	//Parse each string in Student Data Table (above) and add each student to roster
	for (int i = 0; i < 5; i++)
	{
		//Parse current string
		string studentDataStr = studentDataTable[i];
		string parsedAttributes[9] = { "", "", "", "", "", "", "", "", "" };
		Roster::parse(studentDataStr, parsedAttributes);

		//Assign student attributes to be passed into Roster::add
		string studentID = *(parsedAttributes);
		string firstName = *(parsedAttributes + 1);
		string lastName = *(parsedAttributes + 2);
		string emailAddress = *(parsedAttributes + 3);
		//Convert strings into ints
		int age = stoi(*(parsedAttributes + 4));
		int daysInCourse1 = stoi(*(parsedAttributes + 5));
		int daysInCourse2 = stoi(*(parsedAttributes + 6));
		int daysInCourse3 = stoi(*(parsedAttributes + 7));
		//Convert string into the DegreeProgram enum
		DegreeProgram degreeProgram = DegreeProgram::SECURITY;
		string degreeProgramStr = *(parsedAttributes + 8);
		if (degreeProgramStr == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (degreeProgramStr == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else if (degreeProgramStr == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}

		//Add student to roster using parsed attributes
		classRoster.add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	}

	//Print roster
	classRoster.printAll();

	//Print invalid emails
	classRoster.printInvalidEmails();

	//Print average days in course for all students in roster
	cout << "Average Days in Course by Student:\n";
	for (int i = 0; i < 5; i++)
	{
		Student** classRosterArr = classRoster.getClassRosterArr();
		Student currentStudent = **(classRosterArr + i);
		string currentStudentID = currentStudent.getStudentID();
		classRoster.printAverageDaysInCourse(currentStudentID);
	}
	cout << "\n";

	//Print students in Software Degree Program
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	//Remove "A3"
	classRoster.remove("A3");

	//Print roster
	classRoster.printAll();

	//Remove "A3" again
	classRoster.remove("A3");

	//Call destructor
	classRoster.~Roster();
}