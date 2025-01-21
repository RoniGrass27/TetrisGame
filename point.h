#pragma once

#include "gameConfig.h"


class Point
{
private:
	int x;
	int y;
	int diff_x;
	int diff_y;
public:
	// Default constructor
	Point() : x(0), y(0), diff_x(0), diff_y(1) {}

	// Parameterized constructor
	Point(int _x, int _y, int _diff_x = 0, int _diff_y = 1);

	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	int getX() const { return x; }
	int getY() const { return y; }

	void draw(char ch, int num) const;

};



