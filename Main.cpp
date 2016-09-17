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

#define XPIECE 6
#define OPIECE 9

// establish screen size
const int screenWidth = 640;		// width of screen window in pixels 
const int screenHeight = 480;		// height of screen window in pixels
GLdouble A, B, C, D;				// values used for scaling and shifting

// Create game board
GameBoard *gameboard;

// Create game pieces
XPiece *xPiece1;
OPiece *oPiece1;

//<<<<<<<<<<<<<<<<<<<<<<< custom random function>>>>>>>>>>>>>>>>>>>>

int random(int m) {
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

	A = screenWidth / 4.0;					// set values used for scaling and shifting
	B = 0.0;
	C = D = screenHeight / 2.0;


}

//<<<<<<<<<<<<<<<<<<<<<<<< myTimer >>>>>>>>>>>>>>>>>
void myTimer(int iUnused)
{
	// update animations and redraw
	// glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< myIdle >>>>>>>>>>>>>>>>>
void myIdle()
{
	// update animations and redraw
	glutPostRedisplay();
}

//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);			// clear the screen 

	gameboard->drawGameBoard();

	xPiece1->draw(GL_RENDER);
	oPiece1->draw(GL_RENDER);

	glutSwapBuffers();						// swap buffers

											// call timer to update animations and screen again
	glutTimerFunc(30, myTimer, 0);

}


//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
int main(int argc, char** argv)
{

	xPiece1 = new XPiece(550, 150, XPIECE);
	oPiece1 = new OPiece(550, 75, OPIECE);

	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);	// set display mode
	glutInitWindowSize(screenWidth, screenHeight);	// set window size
	glutInitWindowPosition(100, 150);				// set window position on screen
	glutCreateWindow("Tic Tac Toe");		// open the screen window

									// register callback functions
	glutDisplayFunc(myDisplay);     // register redraw function


	myInit();						// additional initializations

	glutIdleFunc(myIdle);

	glutMainLoop(); 				// perpetual loop

	return 0;
}