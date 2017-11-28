// Project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GradeBook.h"
#include "iostream"
using namespace std;


int main()
{
	string courseName;
	//GradeBook myGradeBook1("CS5100: introduction to basic C++ programming");//create a GradeBook object named myGradeBook1
	GradeBook myGradeBook2("CS5200: JAVA programming");//create a GradeBook object named myGradeBook2
	////Prompt for and input course name
	//cout << "Please enter the course name:" << endl;
	//getline(cin, courseName);
	//myGradeBook.setCourseName(courseName);
	//cout << endl;
	//Display grade book with name of course
	/*cout << "gradeBook1 created for course: " << myGradeBook1.getCourseName()
		 << "\ngradeBook2 created for course: " << myGradeBook2.getCourseName()
		 << endl;*/
	myGradeBook2.displayMessage();
	myGradeBook2.determineClassAverage();
	system("PAUSE");
	return 0;
}

