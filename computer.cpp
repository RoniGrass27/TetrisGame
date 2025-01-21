#include "computer.h"



void Computer::calculateMove(Shape& shape, int* MaxRowsToDelete, int* maxY, int* StepsToSides) {

	Point tempBody[4]; // Temporary body array


	int bestCol = 0;

	const Point* p = shape.getBody();
	int minX = findMinX(p);



	for (int j = 0; j < GameConfig::GAME_WIDTH; j++) {
		// Copy the body points to the temporary array
		for (int i = 0; i < 4; ++i) {
			tempBody[i] = p[i];
		}

		bool moveIsOk = true;
		int counter = 0;

		if (MoveSides(tempBody, minX, j) == true)
		{
			for (int i = 0; i < 4; i++) {
				tempBody[i].setX(((p[i].getX()) - minX) + j); // Modify the temporary array
			}
			while (moveIsOk)
			{

				for (int i = 0; i < 4; i++) {

					tempBody[i].setY(p[i].getY() + counter); // Modify the temporary array

					if (this->board.checkCell(tempBody[i]) != true) {
						moveIsOk = false;
					}
				}

				counter++; //count the num of rows it can go down
			}

			int TempRowsToDelete = updateAndCheck(tempBody);

			if (TempRowsToDelete > *MaxRowsToDelete) { //prefer a case where the number of lines to delete is greater
				*MaxRowsToDelete = TempRowsToDelete;
				*maxY = counter - 1;
				bestCol = j;
			}
			else if (*maxY < counter - 1 && (*MaxRowsToDelete) == 0) //In case there are no lines to delete, the function determines the best move according to the maximum y that the shape can reach
			{
				*maxY = counter - 1;
				bestCol = j;
			}

		}

	}
	*StepsToSides = bestCol - minX;
}


int Computer::updateAndCheck(Point tempBody[]) {

	for (int i = 0; i < 4; i++)
	{
		this->board.updateBoard(tempBody[i], this->currentShape.getChar());
	}
	int TempRowsToDelete = checkRows();
	for (int i = 0; i < 4; i++)
	{
		this->board.updateBoard(tempBody[i], ' ');
	}
	return TempRowsToDelete;
}


bool Computer::MoveSides(Point tempBody[], int minX, int j) 
//The function checks if the shape can move sideways up to the column we want to check, if not it returns false
{
	int steps = j - minX;
	for (int i = 1; i <= std::abs(steps); i++)
	{
		for (int k = 0; k < 4; k++) {


			if (steps < 0)
			{

				if (!(this->board.checkCell(tempBody[k], -1, 0)))
				{
					return false;
				}
				tempBody[k].setX(tempBody[k].getX() - 1);
			}
			else
			{

				if (!(this->board.checkCell(tempBody[k], 1, 0)))
				{
					return false;
				}
				tempBody[k].setX(tempBody[k].getX() + 1);
			}
		}
	}
	return true;
}

int Computer::checkRows() const {
	Point p;
	int rows = 0;
	for (int i = 0; i < GameConfig::GAME_HEIGHT; i++) //going over each row
	{
		p.setY(i);
		bool rowIsFull = true;

		for (int j = 0; j < GameConfig::GAME_WIDTH; j++) //going over each col
		{
			p.setX(j);

			if (this->board.checkCell(p, 0, 0)) {
				rowIsFull = false; //If a cell without an asterisk is encountered, it moves to the next row without continuing to check the row
				break;
			}
		}

		if (rowIsFull) {
			rows++;
		}
	}
	return rows;
}

void Computer::run(Shape& currentShape, char key, int num, bool* over, bool* turnFinish, bool* firstShape){

	
	int TempMaxRowsToDelete = 0;
	int TempMaxY = 0;
	int bestDirection = 0;
	int TempStepsToSides = 0;
	

 	if (*turnFinish || *firstShape == true) 
	 //Creates a new shape if it is the first shape or the previous shape was placed on the board
	{
		currentShape = getShapeAndCheck(this->board, over);
		if (*over == true)
		{
			return;
		}
		else
		{
			currentShape.drawShape(currentShape.getChar(), num);
			*turnFinish = false;


			if (currentShape.startPosComp(num, this->board) == 1) {
				currentShape.doMove(num, 0, 1);
			}
			else if (currentShape.startPosComp(num, this->board) == 2)
			{
				currentShape.doMove(num, 0, 2);


				for (int i = 1; i < 5; i++)
				//calculates for each rotation of the shape the best move, performs comparisons and determines which is the best move among all
				{

					currentShape.rotateShape90CW();
					calculateMove(currentShape, &TempMaxRowsToDelete, &TempMaxY, &TempStepsToSides);
					if (TempMaxRowsToDelete > getMaxRowsToDelete()) {
						setMaxRowsToDelete(TempMaxRowsToDelete);
						bestDirection = i;
						setStepsToSides(TempStepsToSides);
						setMaxY(TempMaxY);
				
					}
					else if (TempMaxY > getMaxY() && getMaxRowsToDelete() == 0)
					{
						setMaxY(TempMaxY);
						bestDirection = i;
						setStepsToSides(TempStepsToSides);
					}
				}
				
				
			}
		}
		computerRotate(bestDirection, num);
	}
	if (getStepsToSides() != 0)
	{
		moveSidesComp(num);
	}
	else if (getMaxY() != 0)
	{
		currentShape.doMove(num, 0, 1);
		setMaxY(getMaxY() - 1);
	}
	else
	{
		*turnFinish = true;
		putShapeInBoard(currentShape, this->board);
		if (currentShape.getChar() == '$')
		{
			bomb(num);
		}
		this->board.checkRowAndDelete(num);
		setMaxRowsToDelete(0);
	}
}


void Computer::moveSidesComp(int num)
{

	if (getStepsToSides() < 0)
	{
		this->currentShape.doMove(num, -1, 0);
		setStepsToSides(getStepsToSides() + 1);
	}
	else
	{
		this->currentShape.doMove(num, 1, 0);
		setStepsToSides(getStepsToSides() - 1);
	}
	
}

void Computer::computerRotate(int direction,int num) {
	for (int i = 0; i < direction; i++)
	{
		this->currentShape.drawShape(' ', num);
		this->currentShape.rotateShape90CW();
		this->currentShape.drawShape(currentShape.getChar(), num);
		Sleep(100);
	}
}