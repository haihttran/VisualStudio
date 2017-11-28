// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string name;
	cout << "Please input your name: ";
	cin >> name;
	cout << "Hello, " << name << ".\n";
	system("pause");
    return 0;
}

