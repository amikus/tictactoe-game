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

	if (winning) {
		// set color to yellow
		glColor3f(1.0f, 1.0f, 0.0f);
	}
	else {
		// set color to green
		glColor3f(0.0f, 1.0f, 0.0f);
	}

	// draw shape
	glRectf(x - 0.25f, y - 0.25f, x + 0.25f, y + 0.25f);

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}


