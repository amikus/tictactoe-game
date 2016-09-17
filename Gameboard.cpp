#include "GameBoard.h"

// GameBoard constructor
GameBoard::GameBoard() {

};


// GameBoard destructor
GameBoard::~GameBoard() {

}

// draw GameBoard
void GameBoard::drawGameBoard() {

	// set color to blue
	glColor3f(0.0f, 0.0f, 1.0f);

	// draw GameBoard
	glBegin(GL_LINES);

		// top line
		glVertex2f(75.0, 325.0);
		glVertex2f(375.0, 325.0);

		// bottom line
		glVertex2f(75.0, 225.0);
		glVertex2f(375.0, 225.0);

		// left line
		glVertex2f(175.0, 425.0);
		glVertex2f(175.0, 125.0);

		// right line
		glVertex2f(275.0, 425.0);
		glVertex2f(275.0, 125.0);

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}