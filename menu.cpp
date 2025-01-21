#include "menu.h"

const char* Menu_board[GameConfig::ROWS] = {
	//	          10        20        30        40        50        60        70       79
	//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+Main Menu:                                                                   +", // 1
		"+ 1. Start a new game - Human vs Human                                        +", // 2
		"+ 2. Start a new game - Human vs Computer                                     +", // 3
		"+ 3. Start a new game - Computer vs Computer                                  +", // 4
		"+ 4. Continue a paused game                                                   +", // 5
		"+ 8. Present instructions and keys                                            +", // 6
		"+ 9. EXIT                                                                     +", // 7
		"+                                                                             +", // 8
		"+                                                                             +", // 9
		"+                                                                             +", // 10
		"+                                                                             +", // 11
		"+                                                                             +", // 12
		"+                                                                             +", // 13
		"+                                                                             +", // 14
		"+                                                                             +", // 15
		"+                                                                             +", // 16
		"+                                                                             +", // 17
		"+                                                                             +", // 18
		"+                                                                             +", // 19
		"+                                                                             +", // 20
		"+                                                                             +", // 21
		"+                                                                             +", // 22
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 23
	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
};

const char* first_board[GameConfig::ROWS] = {
	//	          10        20        30        40        50        60        70       79
	//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+Main Menu:                                                                   +", // 1
		"+ 1. Start a new game - Human vs Human                                        +", // 2
		"+ 2. Start a new game - Human vs Computer                                     +", // 3
		"+ 3. Start a new game - Computer vs Computer                                  +", // 4
		"+ 8. Present instructions and keys                                            +", // 5
		"+ 9. EXIT                                                                     +", // 6
		"+                                                                             +", // 7
		"+                                                                             +", // 8
		"+                                                                             +", // 9
		"+                                                                             +", // 10
		"+                                                                             +", // 11
		"+                                                                             +", // 12
		"+                                                                             +", // 13
		"+                                                                             +", // 14
		"+                                                                             +", // 15
		"+                                                                             +", // 16
		"+                                                                             +", // 17
		"+                                                                             +", // 18
		"+                                                                             +", // 19
		"+                                                                             +", // 20
		"+                                                                             +", // 21
		"+                                                                             +", // 22
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 23
	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
};

const char* ins_board[GameConfig::ROWS] = {
	//	          10        20        30        40        50        60        70       79
	//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+------------------------- TETRIS GAME INSTRUCTIONS --------------------------+", // 1
		"+you must arrange a sequence of small shapes, called Tetraminos,              +", // 2
		"+into complete lines.                                                         +", // 3
		"+As each line is completed, it will disappear from the screen.                +", // 4
		"+if you cannot complete a line, the blocks will eventually stack up and rise  +", // 5
		"+to the top of the playing field and the game will end.                       +", // 6
		"+                                                                             +", // 7
		"+KEYS:                                                                        +", // 8
		"+ Left Player: LEFT- a or A , RIGHT- d or D , DROP- x or X                    +", // 9
		"+ ROTATE clockwise- s or S, ROTATE counterclockwise- w or W                   +", // 10
		"+                                                                             +", // 11
		"+ right player: LEFT- j or J, RIGHT- l OR L, DROP- m or M                     +", // 12
		"+ ROTATE clockwise- k or K, ROTATE counterclockwise- i or I                   +", // 13
		"+                                                                             +", // 14
		"+                                                                             +", // 15
		"+                                                                             +", // 16
		"+                                                                             +", // 17
		"+ Ready to play? Press ESC to back to the Menu and start!                     +", // 18
		"+                                                                             +", // 19
		"+                                                                             +", // 20
		"+                                                                             +", // 21
		"+                                                                             +", // 22
		"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 23
	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
};

