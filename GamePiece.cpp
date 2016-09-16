#include "GamePiece.h"

// Turtle constructor
GamePiece::GamePiece() {



	// draw the Turtle
	drawGamePiece();
};


// GamePiece destructor
GamePiece::~GamePiece() {

}

// draw GamePiece and dot array
void GamePiece::drawGamePiece() {

	// draw dot array
	vector<Point>::const_iterator it;
	for (it = points.begin(); it != points.end(); ++it) {
		glBegin(GL_POINTS);
		glVertex2i((*it).x, (*it).y);
		glEnd();
	}

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


