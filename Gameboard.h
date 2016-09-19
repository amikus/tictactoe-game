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

protected:

	// unchanging variables

	// changeable variables
	static char boardState[9];			// 3x3 grid for placement of pieces
	static int winStates[8][3];			// combinations that result in win state
public:

	void drawGameBoard();				// draw shape and dot array

	void updateBoardState(int x, int y);				// update state of GameBoard

	GameBoard();						//  constructor
	~GameBoard();						//  destructor


};