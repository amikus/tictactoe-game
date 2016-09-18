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
	
	if (winning) {
		// set color to yellow
		glColor3f(1.0f, 1.0f, 0.0f);
	}
	else {
		// set color to red
		glColor3f(1.0f, 0.0f, 0.0f);
	}

	// draw shape
	glRectf(x - 0.25f, y - 0.25f, x + 0.25f, y + 0.25f);

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}
