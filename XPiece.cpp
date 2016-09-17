#include "XPiece.h"

// XPiece constructor
XPiece::XPiece(GLfloat x, GLfloat y, GLfloat *c, GLint id): GamePiece(x, y, color, id)  {

};


// XPiece destructor
XPiece::~XPiece() {

}

// draw XPiece
void XPiece::draw(GLenum mode) {

	if (mode == GL_SELECT) glLoadName(id);

	// set color
	glColor3fv(color);

	// draw shape
	glBegin(GL_POLYGON);
		glVertex2f(x - 1.5, y - 1.5);
		glVertex2f(x + 1.0, y + 1.0);
		glVertex2f(x + 1.5, y + 0.5);
	glEnd();

}


