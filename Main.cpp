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

#define SIZE 8

#define XPIECE 6
#define OPIECE 9

// establish screen size
const int screenWidth = 640;		// width of screen window in pixels 
const int screenHeight = 480;		// height of screen window in pixels
GLdouble A, B, C, D;				// values used for scaling and shifting

// Create game board
GameBoard *gameboard;

// Create game piece holders for click event
XPiece *xPiece;
OPiece *oPiece;
GamePiece *object;

//<<<<<<<<<<<<<<<<<<<<<<< custom random function>>>>>>>>>>>>>>>>>>>>

int random(int m)
{
	return rand() % m;
}

// I don't understand this function...
double d2w(int d) {
	return (d / screenWidth) * 4.0 - screenHeight;
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
	xPiece->draw(GL_RENDER);
	oPiece->draw(GL_RENDER);

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
		case XPIECE:
			object = xPiece;
			
			// verify click is working
			cout << "X piece!\n";

			break;
		case OPIECE:
			object = oPiece;
			
			// verify click is working
			cout << "O piece!\n";
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
		//xPiece->draw(GL_SELECT);
		//oPiece->draw(GL_SELECT);

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
}

void myMotion(int x, int y)
{
	// set new xy coordinates for object that's clicked on
	//object->setXY(d2w(x), d2w(screenHeight - y));
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
	xPiece = new XPiece(1.25, 0.25, XPIECE);
	oPiece = new OPiece(1.25, 1.0, OPIECE);

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