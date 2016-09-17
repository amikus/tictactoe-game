#include "GameBoard.h"

// GameBoard constructor
GameBoard::GameBoard() {

};


// GameBoard destructor
GameBoard::~GameBoard() {

}

// draw GameBoard
void GameBoard::drawGameBoard() {

	GLfloat barLeft = -1.5;
	GLfloat barRight = 0.0;
	GLfloat barTop = 1.0;
	GLfloat barBottom = 0.5;
	
	GLfloat postLeft = -1.0;
	GLfloat postRight = -0.5;
	GLfloat postTop = 1.5;
	GLfloat postBottom = 0.0;

	// set color to blue
	glColor3f(0.0f, 0.0f, 1.0f);

	// draw GameBoard
	glBegin(GL_LINES);

		// top line
		glVertex2f(barLeft, barTop);
		glVertex2f(barRight, barTop);

		// bottom line
		glVertex2f(barLeft, barBottom);
		glVertex2f(barRight, barBottom);

		// left line
		glVertex2f(postLeft, postTop);
		glVertex2f(postLeft, postBottom);

		// right line
		glVertex2f(postRight, postTop);
		glVertex2f(postRight, postBottom);

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}