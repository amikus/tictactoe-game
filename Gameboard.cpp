#include "GameBoard.h"

char GameBoard::boardState[9];

int GameBoard::winStates[8][3] = { { 0, 1, 2 },
{ 3, 4, 5 },
{ 6, 7, 8 },
{ 0, 3, 6 },
{ 1, 4, 7 },
{ 2, 5, 8 },
{ 0, 4, 8 },
{ 2, 4, 6 } };

// GameBoard constructor
GameBoard::GameBoard() {
	for (int i = 0; i < 9; i++) {
		boardState[i] = ' ';
	}
};

// GameBoard destructor
GameBoard::~GameBoard() {

}



// draw GameBoard
void GameBoard::drawGameBoard() {

	GLfloat barLeft = -1.5;
	GLfloat barRight = 0.0;
	GLfloat barTop = 1.0;
	GLfloat barBottom = 0.5;
	
	GLfloat postLeft = -1.0;
	GLfloat postRight = -0.5;
	GLfloat postTop = 1.5;
	GLfloat postBottom = 0.0;

	// set color to blue
	glColor3f(0.0f, 0.0f, 1.0f);

	// draw GameBoard
	glBegin(GL_LINES);

		// top line
		glVertex2f(barLeft, barTop);
		glVertex2f(barRight, barTop);

		// bottom line
		glVertex2f(barLeft, barBottom);
		glVertex2f(barRight, barBottom);

		// left line
		glVertex2f(postLeft, postTop);
		glVertex2f(postLeft, postBottom);

		// right line
		glVertex2f(postRight, postTop);
		glVertex2f(postRight, postBottom);

	glEnd();

	// set color back to white
	glColor3f(1.0f, 1.0f, 1.0f);

}

int GameBoard::checkBoardPosition(float x, float y)
{
	if (x > -1.5 && x < -1.0 && y > 1.0 && y < 1.5) {
		return 1;
	}
	else if (x > -1.0 && x < -0.5 && y > 1.0 && y < 1.5) {
		return 2;
	}
	else if (x > -0.5 && x < 0.0 && y > 1.0 && y < 1.5) {
		return 3;
	}

	else if (x > -1.5 && x < -1.0 && y > 0.5 && y < 1.5) {
		return 4;
	}
	else if (x > -1.0 && x < -0.5 && y > 0.5 && y < 1.5) {
		return 5;
	}
	else if (x > -0.5 && x < 0.0 && y > 0.5 && y < 1.5) {
		return 6;
	}

	else if (x > -1.5 && x < -1.0 && y > 0.0 && y < 0.5) {
		return 7;
	}
	else if (x > -1.0 && x < -0.5 && y > 0.0 && y < 0.5) {
		return 8;
	}
	else if (x > -0.5 && x < 0.0 && y > 0.0 && y < 0.5) {
		return 9;
	}
	else {
		return 0;
	}

}

void GameBoard::updateBoardState(int boardSpace)
{

}