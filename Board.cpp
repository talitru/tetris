#include "Board.h"
#include "gotoxy.h"

Board::Board()
{
	initBoard();
}

void Board::initBoard()
{
	
	//נראה לי שאמור להיות מודפס לוח רק אם המשתמש בוחר להתחיל או להמשיך משחק
	for (int i = 0; i <= 2 * ROWS + 2; i++)
	{
		for (int j = 0; j <= COLS + 1; j++)
		{
			if (j == 0 || j == COLS + 1 || i == 0 || i == ROWS + 1 || i == 2 * ROWS + 2)
			{
				gotoxy(i, j);
				cout << '#';
				GameBoard[i][j].SetPoint(i, j, false, ' ');

			}

			else
			{
				gotoxy(i, j);
				cout << ' ';
				GameBoard[i][j].SetPoint( i,j,true,' ');
			}
		}
	}

	printMenu();
}

void Board::printMenu()
{
	gotoxy(0, COLS + 3);
	cout << "Please select one of the options:" << endl;
	cout << "(1) Start a new game" << endl;
	cout << "(2) Continue a paused game/resume game" << endl;
	cout << "(8) Present instructions and keys" << endl;
	cout << "(9) EXIT" << endl;
}