/* BadproG.com */

#ifndef BADPROGTRIANGLE_H_
#define BADPROGTRIANGLE_H_

#include <GL/glut.h>
#include <GL/freeglut.h>

/**
* Define
*/
#define SCREEN_TITLE         "Hello World! :D"
#define SCREEN_WIDTH         600
#define SCREEN_HEIGHT         600
#define SCREEN_POSITION_X     100
#define SCREEN_POSITION_Y     100

/**
* Structure
*/
typedef struct s_badprog
{
	int screenPositionX;
	int screenPositionY;

	double side;
	double hyp;
	double sideHalf;
	double sideToFind;
	double ratio;

	GLclampf bgRed;
	GLclampf bgGreen;
	GLclampf bgBlue;
	GLclampf bgAlpha;

	GLfloat    drawRed;
	GLfloat    drawGreen;
	GLfloat    drawBlue;

	GLfloat z;
	GLfloat x1;
	GLfloat x2;
	GLfloat x3;
	GLfloat y1;
	GLfloat y2;
	GLfloat y3;

} t_badprog;

class BadprogTriangle {
public:
	BadprogTriangle(int *ac, char *av[]);
	virtual ~BadprogTriangle();

	static void initValues(t_badprog *bp);
	static void initProgram(t_badprog *bp);
	static void managerDisplay(void);
	static void managerKeyboard(unsigned char key, int x, int y);
	static void managerResize(int w, int h);
	static void managerMover(int w, int h);
	static void managerClicker(int button, int state, int x, int y);
};

#endif /* BADPROGTRIANGLE_H_ */