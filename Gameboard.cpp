#include "GameBoard.h"

// GameBoard constructor
GameBoard::GameBoard() {

};


// GameBoard destructor
GameBoard::~GameBoard() {

}

// draw GameBoard
void GameBoard::drawGameBoard() {

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}