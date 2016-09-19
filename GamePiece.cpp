#include "GamePiece.h"

// GamePiece constructor
GamePiece::GamePiece(GLfloat x, GLfloat y, GLint id) {
	this->x = x;
	this->y = y;
	this->id = id;
	this->draggable = true;
	this->winning = false;
};


// GamePiece destructor
GamePiece::~GamePiece() {

}

// set xy positions
void GamePiece::setXY(GLfloat x, GLfloat y) {
	this->x = x;
	this->y = y;
};

int GamePiece::getX() {
	return x;
};

int GamePiece::getY() {
	return y;
};

// set win state
void GamePiece::setWinning(GLboolean winning) {
	this->winning = winning;
};

// get win state
GLboolean GamePiece::getWinning() {
	return winning;
}

// set drag state
void GamePiece::setDraggable(GLboolean draggable) {
	this->draggable = draggable;
}

// get drag state
GLboolean GamePiece::getDraggable() {
	return draggable;
}