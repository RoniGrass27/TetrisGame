#pragma once
#include "gameConfig.h"
#include "general.h"
#include "point.h"
#include <iostream>



class Board {
private:
	char board[GameConfig::GAME_HEIGHT][GameConfig::GAME_WIDTH];


public:
	//default Constructor
	Board() = default;

	// Public member functions

	void initBoard();
	void updateBoard(Point p, char symbol);
	bool checkCell(const Point& p, int diff_x = 0, int diff_y = 1) const;
	void checkRowAndDelete(int num);
	void deleteRow(int row);
	void drawBoard(int num) const;

	// Getter for board
	const char(*getBoard() const)[GameConfig::GAME_WIDTH] {
		return board;
	}

};















