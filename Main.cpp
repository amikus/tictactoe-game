// necessary headers/libraries
#include <math.h>
#include <iostream>
#include <random>
#include <stdlib.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "XPiece.h"
#include "OPiece.h"
#include "GamePiece.h"
#include "Gameboard.h"
#include "Main.h"

#define SIZE 8

#define XPIECE1 11
#define XPIECE2 12
#define XPIECE3 13
#define XPIECE4 14
#define XPIECE5 15

#define OPIECE1 21
#define OPIECE2 22
#define OPIECE3 23
#define OPIECE4 24
#define OPIECE5 25

// establish screen size
const int screenWidth = 640;		// width of screen window in pixels 
const int screenHeight = 480;		// height of screen window in pixels
GLdouble A, B, C, D;				// values used for scaling and shifting

// Create game board
GameBoard *gameboard;

// Create game piece holders for click events
XPiece *xPiece1;
XPiece *xPiece2;
XPiece *xPiece3;
XPiece *xPiece4;
XPiece *xPiece5;
OPiece *oPiece1;
OPiece *oPiece2;
OPiece *oPiece3;
OPiece *oPiece4;
OPiece *oPiece5;
GamePiece *object;

//<<<<<<<<<<<<<<<<<<<<<<< custom random function>>>>>>>>>>>>>>>>>>>>

int random(int m)
{
	return rand() % m;
}


double d2w(int d) {
	return (d / 500.0) * 4.0 - 2.0;
}


//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);		// background color: black
	glColor3f(1.0f, 1.0f, 1.0f);			// drawing color: white 
	glLineWidth(5.0);						// a line is 5 pixels wide
	glMatrixMode(GL_PROJECTION); 			// set "camera shape"
	glLoadIdentity();						// reset matrix
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
}

//<<<<<<<<<<<<<<<<<<<<<<<< displayText >>>>>>>>>>>>>>>>>
void displayText(GLfloat x, GLfloat y, char *p, GLfloat scale)
{
	glPushMatrix();

		// position and scale text
		glTranslatef(x, y, 0);
		glScalef(scale, scale, scale);

		// cycle through characters
		for (; *p; p++)
		{
			glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
		}

	glPopMatrix();

}
//<<<<<<<<<<<<<<<<<<<<<<<< myIdle >>>>>>>>>>>>>>>>>
void myIdle()
{
	// redraw the screen / update animations
	glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	// clear screen to background color
	glClear(GL_COLOR_BUFFER_BIT);

	// draw gameboard
	gameboard->drawGameBoard();

	// draw pieces
	xPiece1->draw(GL_RENDER);
	xPiece2->draw(GL_RENDER);
	xPiece3->draw(GL_RENDER);
	xPiece4->draw(GL_RENDER);
	xPiece5->draw(GL_RENDER);
	oPiece1->draw(GL_RENDER);
	oPiece2->draw(GL_RENDER);
	oPiece3->draw(GL_RENDER);
	oPiece4->draw(GL_RENDER);
	oPiece5->draw(GL_RENDER);

	// write words
	glColor3f(1.0f, 1.0f, 1.0f);						// set word color to white
	displayText(-1.75f, -1.0f, "Andrew Klem's", 0.004);
	displayText(-1.75f, -1.75f, "Tic Tac Toe", 0.004);

	// swap buffers
	glutSwapBuffers();

}

//<<<<<<<<<<<<<<<<<<<<< processHits >>>>>>>>>>>>>>
void processHits(GLint hits, GLuint buffer[], int x, int y) {

	GLuint *ptr;
	ptr = (GLuint *)buffer + 3;

	if (hits == 0) {
		cout << "You didn't even hit it!\n";
		return;
	}

	switch (*ptr) {
		case XPIECE1:
			object = xPiece1;
			break;
		case XPIECE2:
			object = xPiece2;
			break;
		case XPIECE3:
			object = xPiece3;
			break;
		case XPIECE4:
			object = xPiece4;
			break;
		case XPIECE5:
			object = xPiece5;
			break;
		case OPIECE1:
			object = oPiece1;
			break;
		case OPIECE2:
			object = oPiece2;
			break;
		case OPIECE3:
			object = oPiece3;
			break;
		case OPIECE4:
			object = oPiece4;
			break;
		case OPIECE5:
			object = oPiece5;
	}

}


//<<<<<<<<<<<<<<<<<<<<<<<< click >>>>>>>>>>>>>>>>>
void click(int x, int y)
{
	GLuint selectBuf[SIZE];
	GLint hits;
	GLint viewport[4];

	glGetIntegerv(GL_VIEWPORT, viewport);

	glSelectBuffer(SIZE, selectBuf);
	glRenderMode(GL_SELECT);

	glInitNames();
	glPushName(0);

	glMatrixMode(GL_PROJECTION);

	// create 5x5-pixel area around cursor location
	glPushMatrix();

		// reset matrix
		glLoadIdentity();

		// create the 5x5 area
		gluPickMatrix((GLdouble)x, (GLdouble)(viewport[3] - y), 5.0, 5.0, viewport);
		gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

		// redraw the pieces
		xPiece1->draw(GL_SELECT);
		xPiece2->draw(GL_SELECT);
		xPiece3->draw(GL_SELECT);
		xPiece4->draw(GL_SELECT);
		xPiece5->draw(GL_SELECT);
		oPiece1->draw(GL_SELECT);
		oPiece2->draw(GL_SELECT);
		oPiece3->draw(GL_SELECT);
		oPiece4->draw(GL_SELECT);
		oPiece5->draw(GL_SELECT);

		glMatrixMode(GL_PROJECTION);

	glPopMatrix();

	glFlush();

	hits = glRenderMode(GL_RENDER);
	
	processHits(hits, selectBuf, x, y);

	glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< myMouse >>>>>>>>>>>>>>>>>
void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		click(x, y);
	}

	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if (object) {
			int boardPosition = gameboard->checkBoardPosition(object->getX(), object->getY());
			
			if (boardPosition != 0) {
				object->setDraggable(false);
			}
		}

	}

}

void myMotion(int x, int y)
{
	// verify that an object has been selected
	if (object) {

		// set new xy coordinates for draggable objects
		if (object->getDraggable()) {
			object->setXY(d2w(x), d2w(500 - y));
		}
		
	}
	glutPostRedisplay();
}

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{

	// Game Pieces
	xPiece1 = new XPiece(1.5, 0.0, XPIECE1);
	xPiece2 = new XPiece(1.5, 0.4, XPIECE2);
	xPiece3 = new XPiece(1.5, 0.8, XPIECE3);
	xPiece4 = new XPiece(1.5, 1.2, XPIECE4);
	xPiece5 = new XPiece(1.5, 1.6, XPIECE5);

	oPiece1 = new OPiece(1.0, 0.0, OPIECE1);
	oPiece2 = new OPiece(1.0, 0.4, OPIECE2);
	oPiece3 = new OPiece(1.0, 0.8, OPIECE3);
	oPiece4 = new OPiece(1.0, 1.2, OPIECE4);
	oPiece5 = new OPiece(1.0, 1.6, OPIECE5);

	//xPiece->setDraggable(false);

	// Basic glut setup
	glutInit(&argc, argv);							// initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// set display mode
	glutInitWindowSize(500, 500);					// set window size
	glutInitWindowPosition(0, 0);					// set window position on screen
	glutCreateWindow("Tic Tac Toe");				// open the screen window

	// register callback functions
	glutMouseFunc(myMouse);			// mouse
	glutMotionFunc(myMotion);		// motion
	glutDisplayFunc(myDisplay);     // redraw
	glutIdleFunc(myIdle);			// idle
	glutReshapeFunc(myReshape);		// resize

	myInit();						// additional initializations

	glutMainLoop(); 				// perpetual loop

	return 0;
}