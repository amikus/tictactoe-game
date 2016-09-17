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



//<<<<<<<<<<<<<<<<<<<<<<< myInit >>>>>>>>>>>>>>>>>>>>
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);		// background color: black
	glColor3f(1.0f, 1.0f, 1.0f);			// drawing color: white 
	glLineWidth(5.0);						// a line is 5 pixels wide
	glMatrixMode(GL_PROJECTION); 			// set "camera shape"
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

	// set values used for scaling and shifting
	A = screenWidth / 4.0;					
	B = 0.0;
	C = D = screenHeight / 2.0;


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
		gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
		//gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

		// redraw the pieces
		xPiece->draw(GL_SELECT);
		oPiece->draw(GL_SELECT);

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

//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{

	// Game Pieces
	xPiece = new XPiece(550, 150, XPIECE);
	oPiece = new OPiece(550, 75, OPIECE);

	// Basic glut setup
	glutInit(&argc, argv);							// initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// set display mode
	glutInitWindowSize(screenWidth, screenHeight);	// set window size
	glutInitWindowPosition(100, 150);				// set window position on screen
	glutCreateWindow("Tic Tac Toe");				// open the screen window

	// register callback functions
	glutMouseFunc(myMouse);

	glutDisplayFunc(myDisplay);     // register redraw function


	myInit();						// additional initializations


	glutIdleFunc(myIdle);

	glutMainLoop(); 				// perpetual loop

	return 0;
}