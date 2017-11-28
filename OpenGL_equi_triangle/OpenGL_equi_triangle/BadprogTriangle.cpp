/* BadproG.com */

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <iostream>
#include <string>
#include "BadprogTriangle.h"

/**
* Init values needed in the program
*/
void BadprogTriangle::initValues(t_badprog *bp)
{
	bp->screenPositionX = 100;
	bp->screenPositionY = 100;

	bp->bgRed = 1;
	bp->bgGreen = 0;
	bp->bgBlue = 1;
	bp->bgAlpha = 0;

	bp->drawRed = 0;
	bp->drawGreen = 1;
	bp->drawBlue = 0;

	bp->side = 3;
	bp->hyp = bp->side;
	bp->sideHalf = bp->hyp / 2;

	bp->sideToFind = pow(bp->hyp, 2) - pow(bp->sideHalf, 2);
	bp->sideToFind = sqrt(bp->sideToFind);
	bp->ratio = pow(bp->sideHalf, 2) / 2;

	bp->z = -8;

	bp->x1 = -1.5;
	bp->x2 = 0;
	bp->x3 = 1.5;

	bp->y1 = 0 - bp->ratio;
	bp->y2 = bp->sideToFind - bp->ratio;
	bp->y3 = 0 - bp->ratio;
}

/**
* Call the initValues() function.
* Set the appropriate background color: glClearColor(pink);
* Set the appropriate shape color: glColor3f(green);
* Clear the window to apply the pink color: glClear().
*/
void BadprogTriangle::initProgram(t_badprog *bp)
{
	initValues(bp);
	glClearColor(bp->bgRed, bp->bgGreen, bp->bgBlue, bp->bgAlpha);
	glColor3f(bp->drawRed, bp->drawGreen, bp->drawBlue);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/**
* Call iniProgram to have the t_badprog structure set.
*
*
* Drawing a shape inside the glBegin(SHAPE) and glEnd() methods.
* Each glVertex3f(x, y, z) methods set a vertex.
* In our case, there are 3 vertices, because we have a triangle.
* We use glutSwapBuffers() instead of glFlush() because we specified
* in the main() that we wanted to use double buffering with GLUT_DOUBLE.
*
*/
void BadprogTriangle::managerDisplay(void)
{
	t_badprog bp;

	initProgram(&bp);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_TRIANGLES);
	glVertex3f(bp.x1, bp.y1, bp.z);
	glVertex3f(bp.x2, bp.y2, bp.z);
	glVertex3f(bp.x3, bp.y3, bp.z);
	glEnd();
	glutSwapBuffers();
}

/**
* By clicking ESC key, you close the window
*/
void BadprogTriangle::managerKeyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
	{
		exit(0);
	}
	}
	(void)(x);
	(void)(y);
}

/**
* By resizing the window, the triangle stays with same proportions.
*/
void BadprogTriangle::managerResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

/**
* Display in the console the x and y of the cursor when the mouse
* is moved and a mouse button clicked.
*/
void BadprogTriangle::managerMover(int x, int y)
{
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl << std::endl;
}

/**
* Display in the console the x and y of the cursor when a button
* is clicked, showing its state (0 or 1) and which button is clicked.
*/
void BadprogTriangle::managerClicker(int button, int state, int x, int y)
{

	std::cout << "button = " << button << std::endl;
	std::cout << "state = " << state << std::endl;
	std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl << std::endl;
}

/**
* All init methods needed by openGL.
* In glutInitDisplayMode() we added GLUT_DOUBLE for double buffering.
*/
BadprogTriangle::BadprogTriangle(int *ac, char *av[]) {
	glutInit(ac, av);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutInitWindowPosition(SCREEN_POSITION_X, SCREEN_POSITION_Y);

	glutCreateWindow(SCREEN_TITLE);

	glutDisplayFunc(&managerDisplay);
	glutKeyboardFunc(&managerKeyboard);
	glutReshapeFunc(&managerResize);
	glutMotionFunc(&managerMover);
	glutMouseFunc(&managerClicker);
	glutMainLoop();
}

/**
* Deleting
*/
BadprogTriangle::~BadprogTriangle() {
}