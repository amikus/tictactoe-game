#include "GamePiece.h"

// GamePiece constructor
GamePiece::GamePiece(GLfloat x, GLfloat y, GLint id) {
	this->x = x;
	this->y = y;
	this->id = id;
};


// GamePiece destructor
GamePiece::~GamePiece() {

}

// set xy positions
void GamePiece::setXY(GLfloat x, GLfloat y) {
	this->x = x;
	this->y = y;
};