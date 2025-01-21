#ifndef __GAME_CONFIG_H
#define __GAME_CONFIG_H
#include "general.h"



class GameConfig
{


public:

	enum  eDisplay { ROWS = 24, COLS = 80, NUM_SHAPES = 7, GAME_WIDTH = 12, GAME_HEIGHT = 18, UPPER_CASE = 32 };
	enum  class eKeys { LEFT1 = 'a', LEFT2 = 'j', RIGHT1 = 'd', RIGHT2 = 'l', ROTATECW1 = 's', ROTATECW2 = 'k', ROTATECCW1 = 'w', ROTATECCW2 = 'i', DROP1 = 'x', DROP2 = 'm', ESC = 27,NONE = '0' };


	enum class start_position { S_X = 6, S_Y = 0 };

	enum class TetrominoType {
		I_SHAPE = 0,
		J_SHAPE = 1,
		L_SHAPE = 2,
		O_SHAPE = 3,
		S_SHAPE = 4,
		T_SHAPE = 5,
		Z_SHAPE = 6,
		B_SHAPE = 7
	};


	static const int COLORS[];
	static const int NUM_OF_COLORS;

	static constexpr int MIN_X_L = 5;
	static constexpr int MIN_X_R = 35;
	static constexpr int MIN_Y = 3;


};

#endif
