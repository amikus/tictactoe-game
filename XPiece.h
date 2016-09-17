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

class XPiece :public GamePiece {

protected:

public:

	XPiece(GLfloat x, GLfloat y, GLint id);				// constructor
	~XPiece();											//  destructor

	virtual void draw(GLenum mode);		// draw piece
};