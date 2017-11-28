//GradeBook.cpp

#include "stdafx.h"
#include "GradeBook.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Constructor of GradeBook
GradeBook::GradeBook(string courseName)
{
	setCourseName(courseName);
}

//function that sets the course name
void GradeBook::setCourseName(string courseName)
{
	//If courseName contains less than 25 characters, do nothing
	if (courseName.length() <= 25) {
		this->courseName = courseName;
	}
	if (courseName.length() > 25) {
		this->courseName = courseName.substr(0, 25);//Strim the name up to 25 characters

		cout << "Name \"" << courseName << "\" exceeds maximum length (25).\n"
			<< "Limiting courseName to first 25 characters.\n" << endl;
	}
	
}

//function that gets the course name
string GradeBook::getCourseName()
{
	return this->courseName;
}

//function that displays a welcome message to the GradeBook user
void GradeBook::displayMessage()
{
	cout << "Welcome to the Grade Book for " << getCourseName() << "!" << endl;

}//end function displayMessage

void GradeBook::determineClassAverage()
{
	int total; //sum of grades entered by user
	int gradeCounter; //number of grades entered
	int grade; //grade value
	double average; //number with decimal point for average

	//Initialization
	total = 0; //total initialized
	gradeCounter = 0; //counter initialized

	//Processing
	//ask user for input
	cout << "Enter grade or -1 to quit: ";
	cin >> grade;

	//loop
	while (grade != -1) {
		total = total + grade;
		gradeCounter += 1;
		//ask user for input
		cout << "Enter grade or -1 to quit: ";
		cin >> grade;
	}

	//Termination
	if (gradeCounter != 0) {
		//calculate average of all grades entered
		average = static_cast<double>(total) / gradeCounter;
		//display total and average
		cout << "\nTotal of all " << gradeCounter << " grades entered is "
			<< total << endl;
		cout << "Class average is " << setprecision(2) << fixed << average << endl;
	}
	else //No grade
		cout << "No grade entered" << endl;
}