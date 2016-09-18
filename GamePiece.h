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
	GLint id;

	GLboolean winning;		// set to True if this is a winning piece
	GLboolean draggable;	// set to True if this is a draggable piece

public:

	GamePiece(GLfloat x, GLfloat y, GLint id);				// constructor
	~GamePiece();											// destructor

	void setXY(GLfloat x, GLfloat y);		// set xy positions

	void setWinning(GLboolean);				// set win state
	GLboolean getWinning();					// get win state

	void setDraggable(GLboolean);			// set drag state
	GLboolean getDraggable();				// get drag state

	virtual void draw(GLenum mode) = 0;		// draw piece

};