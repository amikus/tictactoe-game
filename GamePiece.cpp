#include "GamePiece.h"

// GamePiece constructor
GamePiece::GamePiece(GLfloat x, GLfloat y, GLfloat *c, GLint id) {
	this->x = x;
	this->y = y;
	color = c;
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