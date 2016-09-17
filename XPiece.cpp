#include "XPiece.h"

// XPiece constructor
XPiece::XPiece(GLfloat x, GLfloat y, GLint id)
	: GamePiece(x, y, id)  {

};


// XPiece destructor
XPiece::~XPiece() {

}

// draw XPiece
void XPiece::draw(GLenum mode) {

	if (mode == GL_SELECT) glLoadName(id);

	// set color to green
	glColor3f(0.0f, 1.0f, 0.0f);

	// draw shape
	glRectf(x - 25.0f, y - 25.0f, x + 25.0f, y + 25.0f);

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


