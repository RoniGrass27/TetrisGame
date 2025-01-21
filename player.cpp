#include "player.h"

void Player::putShapeInBoard(Shape& shape, Board& board) {

    const Point* p = shape.getBody();

    for (int i = 0; i < 4; i++)
    {
        board.updateBoard(p[i], this->currentShape.getChar());
    }
}


void Player::initializeShapeArr() //Initializes the array of shapes according to where each shape first appears
{

    shapesArr[(int)GameConfig::TetrominoType::I_SHAPE] = Shape('*', Point(5, 0), Point(6, 0), Point(7, 0), Point(8, 0));
    shapesArr[(int)GameConfig::TetrominoType::J_SHAPE] = Shape('*', Point(7, 0), Point(5, 1), Point(6, 1), Point(7, 1));
    shapesArr[(int)GameConfig::TetrominoType::L_SHAPE] = Shape('*', Point(5, 0), Point(5, 1), Point(6, 1), Point(7, 1));
    shapesArr[(int)GameConfig::TetrominoType::O_SHAPE] = Shape('*', Point(6, 0), Point(7, 0), Point(6, 1), Point(7, 1));
    shapesArr[(int)GameConfig::TetrominoType::S_SHAPE] = Shape('*', Point(6, 0), Point(7, 0), Point(5, 1), Point(6, 1));
    shapesArr[(int)GameConfig::TetrominoType::T_SHAPE] = Shape('*', Point(5, 0), Point(6, 0), Point(7, 0), Point(6, 1));
    shapesArr[(int)GameConfig::TetrominoType::Z_SHAPE] = Shape('*', Point(5, 0), Point(6, 0), Point(6, 1), Point(7, 1));
	shapesArr[(int)GameConfig::TetrominoType::B_SHAPE] = Shape('$', Point(6, 0), Point(7, 0), Point(6, 1), Point(7, 1));
};


bool Player::gameIsOver(Shape currentShape,Board& board) const
{
    //Checks if there is room on the board to put another shape, if there is space the game returns false (game not over)
    bool gameIsover = false;
	
	const Point* p = currentShape.getBody();
	
    for (int i = 0; i < 4; i++)
    {
		
        int x = (p+i)->getX();
        int y = (p+i)->getY();
		
		if (this->board.getBoard()[y][x] != ' ')
		{
			system("cls");
			return true;
		}
	}
        
    
    return false;
}

 Shape& Player::getShapeAndCheck(Board& board, bool* over)
{
	 
	 int currentShapeIND;

	 // 5% chance for a bomb shape
	 if (rand() % 100 < 5) {
		 currentShapeIND = (int)GameConfig::TetrominoType::B_SHAPE;
		 
	 }
	 else {
		 // 95% chance for the random shape
		 currentShapeIND = rand() % GameConfig::NUM_SHAPES;
	 }

	 Shape& currentShape = shapesArr[currentShapeIND];

     
	if (gameIsOver(currentShape, board))
	{
		*over = true;
		std::cout << "game is over!" << std::endl;

	}
	
	return currentShape;
}

 
 


 void Player::bomb(int num) {
	 const Point* p = this->currentShape.getBody();
	 int bombX = findMinX(p);
	 int bombY1 = findMaxY(p);
	 int bombY2 = (findMaxY(p) - 1);


		 // Delete four blocks on the right for both rows of the bomb
		 for (int i = bombX; i < bombX + 4 && i < GameConfig::GAME_WIDTH; i++) 
		     {
				 this->board.updateBoard(Point(i, bombY1,0,0), ' ');  
				 Point(i, bombY1,0,0).draw(' ', num);  
				 this->board.updateBoard(Point(i, bombY2,0,0), ' ');  
				 Point(i, bombY2,0,0).draw(' ', num);  
			 }
		 

		 // Delete four blocks to the left for both rows of the bomb
		 for (int i = bombX - 1; i >= bombX - 4 && i>=0 ; i--) 
			 {
				 this->board.updateBoard(Point(i, bombY1,0,0), ' ');  
				 Point(i, bombY1,0,0).draw(' ', num);  
				 this->board.updateBoard(Point(i, bombY2,0,0), ' ');  
				 Point(i, bombY2,0,0).draw(' ', num);  
			 }
		 

		 // Delete four blocks directly below the bomb for the second row
		 for (int i = bombY1 + 1; i <= bombY1 + 4 && i < GameConfig::GAME_HEIGHT; ++i)
		     {
				 this->board.updateBoard(Point(bombX, i,0,0), ' '); 
				 Point(bombX, i,0,0).draw(' ', num);  
				 this->board.updateBoard(Point(bombX+1, i, 0, 0), ' ');  
				 Point(bombX+1, i, 0, 0).draw(' ', num);  
			 }
		 

		 // Delete the bomb from the screen
		 this->currentShape.drawShape(' ', num);
	 }


 int Player::findMinX(const Point* p) {
	 int minX = p[0].getX();
	 for (int i = 1; i < 4; i++) {
		 if (p[i].getX() < minX)
		 {
			 minX = p[i].getX();
		 }
	 }
	 return minX;
 }

 int Player::findMaxY(const Point* p) {
	 int maxY = p[0].getY();
	 for (int i = 1; i < 4; i++) {
		 if (p[i].getY() > maxY) {
			 maxY = p[i].getY();
		 }
	 }
	 return maxY;
 }