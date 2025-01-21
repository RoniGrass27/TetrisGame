#include "tetrisGame.h"

void TetrisGame::printPage(const char* boardToCopy[GameConfig::ROWS]) const
{
    std::cout.flush();
    //going over each row
    for (int i = 0; i < GameConfig::ROWS; i++)
    {
        //going over each col
        for (int j = 0; j < GameConfig::COLS; j++)
        {
            //going to the place on the board
            gotoxy(j, i);
            //printing the needed char based on the default board
            std::cout << boardToCopy[i][j];
        }
    }
}


void TetrisGame::runMenu(bool* exitGame) {

    bool  displayI = true;

    char key;
    char runKey = NULL;

    while (!(*exitGame)) //As long as the number 9 is not pressed
    {

        Sleep(400);


        if (_kbhit())
        {
            key = _getch();
        }
        else
        {
            key = runKey;
        }
        switch (key)
        {
        case '1': //start a new game H vs H            
            runKey = runrun(exitGame, 1);
            break;

        case '2': //start a new game H vs C
            runKey = runrun(exitGame, 2);
            break;

        case '3': //start a new game C vs C
            runKey = runrun(exitGame, 3);
            break;

        case '8'://instruction or keys
            displayI = true;
            clrscr();
            printPage(ins_board);
            while (displayI)
            {
                if (_kbhit()) {
                    key = _getch();
                    if (key == (char)GameConfig::eKeys::ESC)
                    {
                        clrscr();
                        displayI = false;
                        printPage(first_board);
                    }
                }
            }
            break;
        case '9': //exit game
            endGame();
            *exitGame = true;
            break;
        default:
            break;
        }
    

    }  
}


void TetrisGame::init() const{

    clrscr();
    drawBoardSomewhere(); //draw borders on the screen

}



char TetrisGame::runrun(bool* exitGame, int caseGame) //main game function
{
    //Init game and create two players according to the user choice
    init();

	if (caseGame == 1) {
		player1 = new Human();
		player2 = new Human();
	}
	else if (caseGame == 2) {
        player1 = new Human();
        player2 = new Computer();
	}
	else if (caseGame == 3) {
		
        player1 = new Computer();
        player2 = new Computer();
	}
    
    player1->getMutableBoard().drawBoard(1);
    player2->getMutableBoard().drawBoard(2);
    bool over = false;
	bool turn1IsFinish = false;
	bool turn2IsFinish = false;
    bool firstShape = true;
	bool gameIsPaused = false;
    char MenukeyPressed = NULL;
  
    while (!over)
    //while 9 is not pressed, continue the game one move every time
    {
		MenukeyPressed =smallLoop(&over, &turn1IsFinish, &turn2IsFinish, &gameIsPaused, &firstShape);

        if(over == true)
        {
            endGame();
            break;
        }

        Sleep(200);

    }
    
    return MenukeyPressed;

}

void TetrisGame::endGame() const
{
    clrscr();
    std::cout << "Game is over" << std::endl;
    Sleep(1000);
    clrscr();
    printPage(first_board);

}

char TetrisGame::pausedGame()
{
    clrscr();
    printPage(Menu_board);
    char keyPressed = _getch();
    return keyPressed;

}

char TetrisGame::smallLoop(bool* over, bool* turn1Finish ,bool* turn2Finish, bool* gameIsPaused, bool* firstShape)
{
    //The function receives keystrokes and sends the appropriate character to the run function
    bool displayI = true;
	GameConfig::eKeys keyPressed;
    char menuKeyPressed, insKey;
    keyPressed = GameConfig::eKeys::NONE;
        
        if (_kbhit())
        {
            keyPressed = (GameConfig::eKeys)_getch();
            if (keyPressed == GameConfig::eKeys::ESC)
            {
                menuKeyPressed = pausedGame();
                if (menuKeyPressed == '8') {
                    clrscr();
                    printPage(ins_board);
                    displayI = true;
                    while (displayI)
                    {
                        if (_kbhit()) {
                            insKey = _getch();
                            if (insKey == (char)GameConfig::eKeys::ESC)
                            {
                             
                                displayI = false;
                            }
                        }
                    }
                    menuKeyPressed = pausedGame();
                }
                else if (menuKeyPressed=='4')
                {
                    init();
                }
                else{
                    *over = true;
                    return menuKeyPressed;
                }

            }
        }
        
        player1->run(this->player1->getMutableCurrentShape(), (char)keyPressed, 1, over, turn1Finish, firstShape);
        player2->run(this->player2->getMutableCurrentShape(),(char)keyPressed, 2, over, turn2Finish, firstShape);
        *firstShape = false;
        Sleep(50);
    
        return NULL;
}



void TetrisGame::drawBoardSomewhere()const { 
    //Draws the board boundaries according to the MIN_X and MIN_Y of each board
    int colCurrent = GameConfig::MIN_X_L - 1;

    for (int board = 0; board < 2; board++)
    {
        if (board == 1)
        {
            colCurrent = GameConfig::MIN_X_R - 1;
        }

        for (int col = colCurrent; col < GameConfig::GAME_WIDTH + colCurrent; col++)
        {
            gotoxy(col, GameConfig::MIN_Y - 2);
            std::cout << "-";

            gotoxy(col, GameConfig::GAME_HEIGHT + GameConfig::MIN_Y - 1);
            std::cout << "-";
        }

        for (int row = GameConfig::MIN_Y - 1; row <= GameConfig::GAME_HEIGHT + GameConfig::MIN_Y - 1; row++)
        {
            gotoxy(colCurrent - 1, row);
            std::cout << "|";

            gotoxy(GameConfig::GAME_WIDTH + colCurrent, row);
            std::cout << "|";
        }
    }
    std::cout << std::endl;
}




