#pragma once
#include <conio.h> // for kbhit+getch
#include <Windows.h> // for Sleep and colors
#include "board.h"
#include "gameConfig.h"
#include "general.h"
#include "point.h"
#include "shape.h"
#include <iostream>



class Player
{
private:
	
	Shape shapesArr[(GameConfig::NUM_SHAPES+1)];

protected:
	Board board;
	Shape currentShape;

public:
	Player() : board(),currentShape(), shapesArr{}
	{
		initializeShapeArr();
		board.initBoard(); // Call the initBoard function from the Board class
	}
	

	Board& getMutableBoard() {
		return board;
	}

	// Getter for currentShape
	const Shape& getCurrentShape() const
	{
		return currentShape;
	}

	// Setter for currentShape
	void setCurrentShape(Shape& newShape)
	{
		currentShape = newShape;
	}

	Shape& getMutableCurrentShape()
	{
		return currentShape;
	}

	virtual ~Player(){};
	void putShapeInBoard(Shape& shape, Board& board);
	void initializeShapeArr();
	bool gameIsOver(Shape currentShape, Board& board)const;
	virtual void run(Shape& currentShape, char key, int num, bool* over, bool* turnFinish, bool* firstShape)=0;
	Shape& getShapeAndCheck(Board& board, bool* over);
	void bomb(int num);
	int findMinX(const Point* p);
	int findMaxY(const Point* p);

};

