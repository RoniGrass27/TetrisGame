#include "human.h"




void Human::run(Shape& currentShape, char key, int num, bool* over, bool* turnFinish, bool* firstShape) {
	

    if(*turnFinish || *firstShape == true)
		//Creates a new shape if it is the first shape or the previous shape was placed on the board
    {
     
        this->currentShape = getShapeAndCheck(this->getMutableBoard(), over);
     if (*over == true)
     {
         return;
     }
     else
     {
		 currentShape.drawShape(currentShape.getChar(), num);
         *turnFinish = false;
     } 
    }
    
     currentShape.move(key, getMutableBoard(), turnFinish, num);//moves one steps each call to the function
     if(*turnFinish)
     {
		 putShapeInBoard(currentShape, getMutableBoard());
		 getMutableBoard().checkRowAndDelete(num);
     }
      bool moveIsOk = true;
      if (moveIsOk = currentShape.checkMove(getMutableBoard(), 0, 1))
      {
          currentShape.doMove(num, 0, 1);
      }
      else
      {
           *turnFinish = true;
		   putShapeInBoard(currentShape, getMutableBoard());
           if(currentShape.getChar() == '$')
           {
               bomb(num);
           }
		   getMutableBoard().checkRowAndDelete(num);
      }
       
 }
