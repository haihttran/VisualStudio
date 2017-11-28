// pointer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

void swapByValue(int numb1, int numb2) {
	numb1 = numb1 + numb2;
	numb2 = numb1 - numb2;
	numb1 = numb1 - numb2;
}

void swapByReference(int *ptr1, int *ptr2) {
	*ptr1 = *ptr1 + *ptr2;
	*ptr2 = *ptr1 - *ptr2;
	*ptr1 = *ptr1 - *ptr2;
}

 

int main()
{
	int numb1 = 1;
	int numb2 = 2;
	cout << numb1 << " " << numb2 << endl;
	swapByValue(numb1, numb2);
	cout << numb1 << " " << numb2 << endl;
	swapByReference(&numb1, &numb2);
	cout << numb1 << " " << numb2 << endl;
	swapByValue(numb1, numb2);
	cout << numb1 << " " << numb2 << endl;
	swapByReference(&numb1, &numb2);
	cout << numb1 << " " << numb2 << endl;
	system("pause");
}

