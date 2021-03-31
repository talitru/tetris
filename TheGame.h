#pragma once

#include "Board.h"
#include "Figure.h"
enum menuKeys { START = '1', PAUSE = '2', INSTRUCTIO_KEYS = '8', EXIT = '9' };
enum { ESC = 27 };//escape
enum { RAND = 7 };

class TheGame
{
	Board GameBoard;
	Figure f;
public:
	void setBoard()
	{
		GameBoard.initBoard();
	}
	void randFigure();

	void StartGame();
	void ChooseOption();
	void ContinueGame();
	void ShowInstructions();
	void ExitGame();


};