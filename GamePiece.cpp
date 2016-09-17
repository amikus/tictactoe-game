#include "GamePiece.h"

// GamePiece constructor
GamePiece::GamePiece() {

	// draw the GamePiece
	drawGamePiece();
};


// GamePiece destructor
GamePiece::~GamePiece() {

}

// draw GamePiece
void GamePiece::drawGamePiece() {

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


