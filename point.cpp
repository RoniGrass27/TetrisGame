#include "point.h"
#include "gameConfig.h"
#include "general.h"
#include <iostream>
#include <Windows.h>


Point::Point(int _x, int _y, int _diff_x, int _diff_y) {
    setX(_x);
    setY(_y);
    diff_x = _diff_x;
    diff_y = _diff_y;
}

void Point::draw(char ch, int num) const
{
    int xOffset = (num == 1) ? GameConfig::MIN_X_L - 1 : GameConfig::MIN_X_R - 1;
    int yOffset = GameConfig::MIN_Y - 1;


    gotoxy(x + xOffset, y + yOffset);
    std::cout << ch;
}
