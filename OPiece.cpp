#include "OPiece.h"

// OPiece Constructor
OPiece::OPiece() {

};


// OPiece destructor
OPiece::~OPiece() {

}

// draw OPiece
void OPiece::drawPiece() {

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}
