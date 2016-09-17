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
	bool draggable;

public:

	virtual void drawPiece();			// draw

	GamePiece();						//  constructor
	~GamePiece();						//  destructor


};