#pragma once
#include <conio.h> // for kbhit+getch
#include <iostream>
#include <Windows.h> // for Sleep and colors
#include <cstdlib>
#include "board.h"
#include "gameConfig.h"
#include "shape.h"
#include "general.h"
#include "point.h"
#include "menu.h"
#include "computer.h"
#include "human.h"
#include "player.h"




class TetrisGame
{
private:
	Player* player1;
	Player* player2;
	

public:
	TetrisGame() : player1(nullptr), player2(nullptr) {};
	~TetrisGame()
	{
		// Clean up dynamically allocated player instances
		delete player1;
		delete player2;
	}
	char smallLoop(bool* over, bool* turn1Finish, bool* turn2Finish, bool* gameIsPaused, bool* firstShape);
	void endGame() const;
	void runMenu(bool* exitGame);
	void printPage(const char* boardToCopy[GameConfig::ROWS]) const;
	void init()const;
	void drawBoardSomewhere()const;
	char runrun( bool* exitGame, int caseGame);
	char pausedGame();
	
};

