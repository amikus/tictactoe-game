#include "OPiece.h"

// OPiece constructor
OPiece::OPiece(GLfloat x, GLfloat y, GLint id) 
	: GamePiece(x, y, id) {

};


// OPiece destructor
OPiece::~OPiece() {

}

// draw OPiece
void OPiece::draw(GLenum mode) {

	if (mode == GL_SELECT) glLoadName(id);
	
	// set color to red
	glColor3f(1.0f, 0.0f, 0.0f);

	// draw shape
	glRectf(x - 25.0f, y - 25.0f, x + 25.0f, y + 25.0f);

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}
