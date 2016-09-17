#pragma once

// required include statements
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "GamePiece.h"

using namespace std;

class OPiece: public GamePiece {

protected:

public:

	OPiece(GLfloat x, GLfloat y, GLfloat *c, GLint id);	// constructor
	~OPiece();											//  destructor

	virtual void draw(GLenum mode);		// draw piece

};