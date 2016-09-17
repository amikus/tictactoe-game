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
	glColor3f(1.0f, 0.0f, 0.0f);

	// draw GamePiece
	glBegin(GL_POLYGON);

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


