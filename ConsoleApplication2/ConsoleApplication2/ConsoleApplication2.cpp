// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int c = 0;
	while (c < 10) {
		cout << a[c] << "\n";
		c++;
	}
	system("pause");
    return 0;
}

