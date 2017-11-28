//GradeBook.h
#pragma once
#include "String"
using namespace std;

class GradeBook
{
public:
	//Constructor of GradeBook
	GradeBook(string);
	//function that sets the course name
	void setCourseName(string);
	//function that gets the course name
	string getCourseName();
	//function that displays a welcome message to the GradeBook user
	void displayMessage();
	void determineClassAverage();//Average grades entered by user
private:
	string courseName;
};//end class GradeBook