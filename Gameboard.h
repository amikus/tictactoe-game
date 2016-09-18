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

	static char boardState[9];			// 3x3 grid for placement of pieces
	static int winStates[8][3];			// combinations that result in win state

	GameBoard();						//  constructor
	~GameBoard();						//  destructor


};