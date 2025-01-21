#pragma once
#include "shape.h"
#include "gameConfig.h"
#include "general.h"
#include "player.h"



class Human: public Player
{


public:
	Human() = default;
	~Human() override{};
	void run(Shape& currentShape, char key, int num, bool* over, bool* turnFinish, bool* firstShape)override;

};

