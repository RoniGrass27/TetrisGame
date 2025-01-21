#include <stdio.h>
#include "shape.h"




void Shape::drawShape(char ch, int num) const
{
	//The function prints the current shape on the screen

	for (int i = 0; i < 4; i++)
	{
		body[i].draw(ch, num);
	}
}

void Shape::moveSND(int diff_x, int diff_y)
{
	//The function moves the shape down and to the sides

	for (int i = 0; i < 4; i++)
	{
		body[i].setX(body[i].getX() + diff_x);
		body[i].setY(body[i].getY() + diff_y);

	}
}


void Shape::doMove(int num, int diff_x, int diff_y) {

	drawShape(' ', num);
	moveSND(diff_x, diff_y);
	drawShape(this->ch, num);
}



void Shape::move(char key, Board& board, bool* lastMove, int num)
{
	//The function moves the shape according to the pressed key according to num of board
	Shape temp(*this);
	bool moveIsOk = true;
	if (num == 1)
	{
		switch (key)
		{
		case (int)GameConfig::eKeys::LEFT1:
		case (int)GameConfig::eKeys::LEFT1 + GameConfig::UPPER_CASE:
			if (moveIsOk = checkMove(board, -1, 0))
			{
				doMove(1, -1, 0);
			}
			break;

		case (int)GameConfig::eKeys::RIGHT1:
		case (int)GameConfig::eKeys::RIGHT1 + GameConfig::UPPER_CASE:
			if (moveIsOk = checkMove(board, 1, 0))
			{
				doMove(1, 1, 0);
			}
			break;

		case (int)GameConfig::eKeys::DROP1:
		case (int)GameConfig::eKeys::DROP1 + GameConfig::UPPER_CASE:
			while (moveIsOk == checkMove(board, 0, 1))
			{
				doMove(1, 0, 1);
			}

			*lastMove = true;
			break;

		case (int)GameConfig::eKeys::ROTATECCW1:
		case (int)GameConfig::eKeys::ROTATECCW1 + GameConfig::UPPER_CASE:
			temp.rotateShape90CCW();
			if (moveIsOk = temp.checkMove(board, 0, 0))
			{
				drawShape(' ', 1);
				rotateShape90CCW();
				drawShape(this->ch, 1);
			}
			break;

		case (int)GameConfig::eKeys::ROTATECW1:
		case (int)GameConfig::eKeys::ROTATECW1 + GameConfig::UPPER_CASE:
			temp.rotateShape90CW();
			if (moveIsOk = temp.checkMove(board, 0, 0))
			{
				drawShape(' ', 1);
				rotateShape90CW();
				drawShape(this->ch, 1);
			}
			break;
		default:
			break;
		}
	}

	else
	{
		switch (key)
		{
		case (int)GameConfig::eKeys::LEFT2:
		case (int)GameConfig::eKeys::LEFT2 + GameConfig::UPPER_CASE:
		if (moveIsOk = checkMove(board, -1, 0))
		{
			doMove(2, -1, 0);
		}
		break;

		case (int)GameConfig::eKeys::RIGHT2:
		case (int)GameConfig::eKeys::RIGHT2 + GameConfig::UPPER_CASE:
		if (moveIsOk = checkMove(board, 1, 0))
		{
			doMove(2, 1, 0);
		}
		break;

		case (int)GameConfig::eKeys::DROP2:
		case (int)GameConfig::eKeys::DROP2 + GameConfig::UPPER_CASE:
		while (moveIsOk == checkMove(board, 0, 1))
		{
			doMove(2, 0, 1);
		}

		*lastMove = true;
		break;

		case (int)GameConfig::eKeys::ROTATECCW2:
		case (int)GameConfig::eKeys::ROTATECCW2 + GameConfig::UPPER_CASE:
		temp.rotateShape90CCW();
		if (moveIsOk = temp.checkMove(board, 0, 0))
		{
			drawShape(' ', 2);
			rotateShape90CCW();
			drawShape(this->ch, 2);
		}
		break;

		case (int)GameConfig::eKeys::ROTATECW2:
		case (int)GameConfig::eKeys::ROTATECW2 + GameConfig::UPPER_CASE:
		temp.rotateShape90CW();
		if (moveIsOk = temp.checkMove(board, 0, 0))
		{
			drawShape(' ', 2);
			rotateShape90CW();
			drawShape(this->ch, 2);
		}
		break;

		default:
		break;
		}
	}
}




void Shape::rotateShape90CCW()
{
	int centerX = body[0].getX();
	int centerY = body[0].getY();
	for (int i = 0; i < 4; ++i)
	{
		int tempX = body[i].getX() - centerX;
		int tempY = body[i].getY() - centerY;
		body[i].setX(centerX + tempY);
		body[i].setY(centerY - tempX);
	}
}

void Shape::rotateShape90CW()
{

	int centerX = body[0].getX();
	int centerY = body[0].getY();
	for (int i = 0; i < 4; ++i)
	{
		int tempX = body[i].getX() - centerX;
		int tempY = body[i].getY() - centerY;
		body[i].setX(centerX - tempY);
		body[i].setY(centerY + tempX);
	}
}



bool Shape::checkMove(Board& board, int diff_x, int diff_y) const
{

	for (int i = 0; i < 4; i++)
	{
		Point p = body[i];
		if ((board.checkCell(p, diff_x, diff_y)) != true)
		{
			return false;
		}

	}
	return true;
}

int Shape::startPosComp(int num, Board& comp) {
	int i;
	for (i = 0; i < 2; i++)
	{
		if (!checkMove(comp, 0, 1)) {
			return i;
		}

	}
	return i;
}


