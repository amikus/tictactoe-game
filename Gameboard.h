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

class GameBoard {

private:

	// unchanging variables

	// changeable variables


public:

	void drawGameBoard();				// draw shape and dot array

	GameBoard();						//  constructor
	~GameBoard();						//  destructor


};