#include "XPiece.h"

// XPiece constructor
XPiece::XPiece() {

};


// XPiece destructor
XPiece::~XPiece() {

}

// draw XPiece
void XPiece::drawPiece() {

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


