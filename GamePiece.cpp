#include "GamePiece.h"

// GamePiece constructor
GamePiece::GamePiece() {

	// draw the GamePiece
	drawPiece();
};


// GamePiece destructor
GamePiece::~GamePiece() {

}

// draw GamePiece
void GamePiece::drawPiece() {

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


