#pragma once
#include "point.h"
#include "gameConfig.h"
#include "board.h"
#include <Windows.h>

class Shape
{
private:
	char ch;
	Point body[4] = { Point() };
	


public:

	// Default constructor
	Shape() : ch('\0'){}

	// Constructor with parameters
	Shape(char _ch, Point p1, Point p2, Point p3, Point p4) : ch(_ch), body{ p1, p2, p3, p4 } {}

	// Copy constructor
	Shape(const Shape&) = default;


	// Copy assignment operator
	Shape& operator=(const Shape&) = default;

	// Getter for body
	const Point* getBody() const {
		return body;
	}

	
	char getChar()const {
		return ch;
	}
	


	void doMove(int num, int diff_x, int diff_y);
	void drawShape(char ch, int num) const;
	void move(char key, Board& board, bool* TurnIsOver, int num);
	bool checkMove(Board& board, int diff_x, int diff_y) const;
	void moveSND(int diff_x, int diff_y);
	void rotateShape90CCW();
	void rotateShape90CW();
	int startPosComp(int num, Board& comp);
};






