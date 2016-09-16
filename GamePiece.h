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

private:

	// unchanging variables

	// changeable variables
	float corner1x, corner1y;
	float corner2x, corner2y;
	float corner3x, corner3y;
	float corner4x, corner4y;
	float angle;

	// used for storing dot coordinates
	struct Point {
		double x, y;
		Point(double px, double py) : x(px), y(py) {}
	};


public:
	// array of dot coordinates
	vector<Point> points;


	void drawGamePiece();				// draw shape and dot array

	GamePiece();			//  constructor
	~GamePiece();						//  destructor


};