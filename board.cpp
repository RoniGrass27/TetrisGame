#include "board.h"



void Board::initBoard() {
    for (int i = 0; i < GameConfig::GAME_HEIGHT; i++)
    {
        for (int j = 0; j < GameConfig::GAME_WIDTH; j++) {
            board[i][j] = ' ';
        }
    }
}



void Board::updateBoard(Point p, char symbol)
{
    int x = p.getX();
    int y = p.getY();

    board[y][x] = symbol;


}


bool Board::checkCell(const Point& p, int diff_x, int diff_y) const
{
    int x = p.getX() + diff_x;
    int y = p.getY() + diff_y;


    // Check if indices are within bounds
    if (x >= 0 && x < GameConfig::GAME_WIDTH && y >= 0 && y < GameConfig::GAME_HEIGHT)
    {
        if (this->board[y][x] != ' ')
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        // Indices are out of bounds
        return false;
    }
}

void Board::checkRowAndDelete(int num) {
    Point p;

    for (int i = 0; i < GameConfig::GAME_HEIGHT; i++) //going over each row
    {
        p.setY(i);
        bool rowIsFull = true;

        for (int j = 0; j < GameConfig::GAME_WIDTH; j++) //going over each col
        {
            p.setX(j);

            if (checkCell(p, 0, 0)) {
                rowIsFull = false; //If a cell without an asterisk is encountered, it moves to the next row without continuing to check the row
                break;
            }
        }

        if (rowIsFull) {
            deleteRow(i);
            drawBoard(num);
        }
    }
}

void Board::deleteRow(int row) {
    for (int i = row; i > 0; i--) {
        for (int j = 0; j < GameConfig::GAME_WIDTH; j++)
        {
            board[i][j] = board[i - 1][j];
            
        }
    }
}


void Board::drawBoard(int num) const {
    int xOffset = (num == 1) ? GameConfig::MIN_X_L - 1 : GameConfig::MIN_X_R - 1;
    int yOffset = GameConfig::MIN_Y - 1;

    for (int i = 0; i < GameConfig::GAME_HEIGHT; i++) {
        for (int j = 0; j < GameConfig::GAME_WIDTH; j++) {
            gotoxy(j + xOffset, i + yOffset);
            std::cout << board[i][j];
        }
    }
}
