// ttt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>          //opening headerfile iostream for in-out
#include<conio.h>             //opening headerfile conio for clrscr();
#include<stdlib.h>            //opening headerfile stdlib for random(int);
#include<cstdlib>
#include<ctime>
using std::cin;
using std::cout;
using std::endl;

const int SIZE = 3;

std::string winning_X;
std::string winning_Y;
char tic[SIZE][SIZE];               //global matrix declerations
int d, e, f, a, t, i, j, x, y;        //global variables declerations
void display();               //displays the matrix
void user();                  //function for user's move
void newdisp();               //function for display of matrix after every move
void pc();                    //function for pc's move
int newhorcheck();
int newvercheck();
int newdiagcheck();
int check();                  //function for finding out the winner
int horcheck();               //function for horizontal line check
int vercheck();               //function for vertical line check
int diagcheck();              //function for diagonal line check
int main()                        //main function
{
	for (int i = 0; i < SIZE; i++) {
		winning_X += 'X';
		winning_Y += 'Y';
	}
	system("cls");                     //clears the previous output screen
	srand((unsigned)time(NULL));                  //initialize random function calling
	int d = rand() % SIZE;              //random function call
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			tic[i][j] = ' ';        //assigning space ' ' to all elements of matrix
	display();                    //display function call
	d == 0 ? user() : pc();             //random starting of the game depending on d
	_getch();                      //provides output by getting input without returning to program
	return 0;                     //return int to main function
}
void display()                //display function definition
{
	for (t = 0; t < SIZE; t++)
	{
		cout << "		" << tic[t][0] << " | " << tic[t][1] << " | " << tic[t][2] << endl;
		//figure formation
		if (t != SIZE)
			cout << "		--|---|--" << endl;
	}
}
void user()                  //user function definition
{
	cout << "ENTER THE CO-ORDINATES WHERE YOU WANT TO PUT UR 'X' i.e 0, 1, 2..." << endl;
	cin >> x >> y;
	if ((x < 0) || (x > SIZE - 1) && (y < 0) || (y > SIZE - 1))  //check for valid co-ordinates
	{
		cout << "ENTER THE CORRECT CO - ORDINATES" << endl;
		user();    //user function call
	}
	else
	{
		if (tic[x][y] == ' ')    //check for vacant space at entered co-ordinates
		{
			tic[x][y] = 'X';  //assigning user 'X' to the co-ordinates
			newdisp();    //newdisp function call
		}
		else
		{
			cout << "THIS POSITION IS ALREADY FILLED.CHOOSE SOME OTHER CO-ORDINATES" << endl;
			user();       //user function call
		}
	}
	d = check();            //check function call
	if (d == 0)
		pc();                 //pc function call
	else
	{
		cout << "YOU ARE THE WINNER" << endl;
		_getche();     //requires enter to return to program. prevents return without display
		exit(1);      //program termination
	}
}
void newdisp()        //newdisp function definition
{
	for (t = 0; t < SIZE; t++)
	{
		cout << "		" << tic[t][0] << " | " << tic[t][1] << " | " << tic[t][2] << endl;
		//displays new tictactoe after user or pc turn
		if (t != SIZE - 1)
			cout << "		--|---|--" << endl;
	}
}
void pc()          //pc function call
{
	int f, z;
	srand((unsigned)time(NULL));                  //initialize random function calling
	cout << "THIS IS THE COMPUTER'S MOVE" << endl;
	for (i = 0; i <= 20; i++)
	{
		f = rand() % SIZE;
		z = rand() % SIZE;
		if (tic[f][z] == ' ')      //check for vacant space at entered co-ordinates
		{
			tic[f][z] = 'O';  //assigning pc 'O' to the co-ordinates
			goto x;         //exiting for loop to display new tictactoe
		}
		else
			continue;               //
	}
x:newdisp();                    //newdisp function call
	d = check();                      //check function call
	if (d == 0)
		user();                         //user function call
	else
	{
		cout << "I'M THE WINNER" << endl;
		_getche();           //requires enter to return to program. prevents	return without display
		exit(1);            //program termination
	}
}
int check()                     //check function definition
{
	newhorcheck();                 //horcheck function call
	newvercheck();                 //vercheck function call
	newdiagcheck();                //diagcheck function call
	return (d || e || f);
}
int horcheck()                  //horcheck function definition
{
	if (((tic[0][0] == tic[0][1]) && (tic[0][1] == tic[0][2]) && (tic[0][1] !=
		' ')) || ((tic[1][0] == tic[1][1]) && (tic[1][1] == tic[1][2]) && (tic[1][1] !=
			' ')) || ((tic[2][0] == tic[2][1]) && (tic[2][1] == tic[2][2]) && (tic[2][2] !=
				' ')))
		d = 1;                        //checks each element of a horizontal line to	be same
	else							//returns 1 if all 3 elements of any horizontal line are same
		d = 0;                        //else returns 0
	return d;
}
//Generic row check
int newhorcheck()                  //horcheck1 function definition
{	
	std::string temp = "";
	d = 0;
	for (int i = 0; i < SIZE; i++) {		
		for (int j = 0; j < SIZE; j++) {
			temp += tic[i][j];
		}
		if ((temp == winning_X) || (temp == winning_Y)) {
			d = 1;			
		}
	}
	return d;
}

int vercheck()                  //vercheck function definition
{
	if (((tic[0][0] == tic[1][0]) && (tic[1][0] == tic[2][0]) && (tic[0][0] !=
		' ')) || ((tic[0][1] == tic[1][1]) && (tic[1][1] == tic[2][1]) && (tic[0][1] !=
			' ')) || ((tic[0][2] == tic[1][2]) && (tic[1][2] == tic[2][2]) && (tic[0][2] !=
				' ')))
		e = 1;                        //checks each element of a vertical line to be same
	else                        //returns 1 if all 3 elements of any vertical line are same
		e = 0;                        //else returns 0
	return e;
}
//Generic column check
int newvercheck()                  //vercheck function definition
{
	std::string temp = "";
	e = 0;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			temp += tic[j][i];
		}
		if ((temp == winning_X) || (temp == winning_Y)) {
			e = 1;			
		}
	}
	return e;
}
int diagcheck()                 //diagcheck function definition
{
	if (((tic[0][0] == tic[1][1]) && (tic[1][1] == tic[2][2]) && (tic[0][0] !=
		' ')) || ((tic[0][2] == tic[1][1]) && (tic[1][1] == tic[2][0]) && (tic[1][1] !=
			' ')))
		f = 1;                        //checks each element of a diagonal line to be same
	else                        //returns 1 if all 3 elements of any diagonal line are same
		f = 0;                        //else returns 0
	return f;
}

int newdiagcheck()                 //diagcheck function definition
{
	std::string temp1 = "";
	std::string temp2 = "";
	f = 0;
	for (int i = 0; i < SIZE; i++) {
		temp1 += tic[i][i];
		temp2 += tic[i][SIZE - i - 1];
		if ((temp1 == winning_X) || (temp1 == winning_Y)
			|| (temp2 == winning_X) || (temp2 == winning_Y)) {
			f = 1;			
		}
	}
	return f;
}

