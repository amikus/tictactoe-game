#include "Text.h"

// Textconstructor
Text::Text() {

};


// Text destructor
Text::~Text() {

}

// draw Text
void Text::drawText() {

	// set color here

	// draw GamePiece
	glBegin(GL_POLYGON);

	// draw stuff here

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}