#define CRT_SECURE_NO_WARNINGS
#include <conio.h> // for kbhit+getch
#include <iostream>
#include <Windows.h> // for Sleep and colors
#include "board.h"
#include "gameConfig.h"
#include "general.h"
#include "shape.h"
#include "point.h"
#include "tetrisGame.h"





int main() {

	srand(static_cast<unsigned>(time(nullptr)));
	TetrisGame game;

	bool exitGame = false;
	while (!exitGame)
	{
		
		game.printPage(first_board);
		game.runMenu(&exitGame);
	}

}
