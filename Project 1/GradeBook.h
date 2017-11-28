#pragma once
#include "iostream"
#include "String"
using namespace std;

class GradeBook
{
public:
	//Constructor of GradeBook
	GradeBook(string courseName)
	{
		setCourseName(courseName);
	}

	//function that sets the course name
	void setCourseName(string courseName)
	{
		this->courseName = courseName;
	}

	//function that gets the course name
	string getCourseName()
	{
		return this->courseName;
	}

	//function that displays a welcome message to the GradeBook user
	void displayMessage()
	{
		cout << "Welcome to the Grade Book for " << getCourseName() << "!" << endl;

	}//end function displayMessage
private:
	string courseName;
};//end class GradeBook