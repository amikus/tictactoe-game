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

using namespace std;

class GamePiece {

protected:

	// unchanging variables

	// changeable variables
	GLfloat x, y;
	GLfloat *color;
	GLint id;

	bool draggable;

public:

	GamePiece(GLfloat x, GLfloat y, GLfloat *c, GLint id);	// constructor
	~GamePiece();											// destructor

	void setXY(GLfloat x, GLfloat y);	// set xy positions
	virtual void draw(GLenum mode) = 0;		// draw piece

	


};