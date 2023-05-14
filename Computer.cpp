#include "headerFiles/Computer.h"

char Computer::ChooseComputerLevel()
{
	char key_char = 0;
	gotoxy(30, 9);
	cout << "Hi! please enter the level of the computer:" << endl;
	gotoxy(30, 10);
	cout << "for the BEST level press (1)" << endl;
	gotoxy(30, 11);
	cout << "for the GOOD level press (2)" << endl;
	gotoxy(30, 12);
	cout << "for the NOVICE level press (3)" << endl;
	while (1)
	{
		if (_kbhit())
		{
			key_char = _getch();
			return key_char;
		}
	}
}
//void Computer::LessSpaces(general* f)
//{
//
//
//	int counterDeletedLines = 0;
//	int maxHeight = 0; // height of the figure in the row
//	int curHeight = 0;
//	
//	for (int i = 0; i < 4; i++)
//	{
//
//		while (update(GameBoard, f->getSerial(), LEFT));
//
//		while(update(GameBoard, f->getSerial(), DOWN));
//
//		for (int i = ROWS; i > 0; i--)
//		{
//			if (GameBoard.IsFullRow(i, RIGHT_PLAYER))
//			{
//				counterDeletedLines++;
//			}
//
//		}
//		for (int j = 0; j < 4; j++) // we calculate the hight of the figure
//		{
//			curHeight = f->getBodyPos(j).gety();
//			if (j == 0)
//			{
//				curHeight = maxHeight;
//			}
//			if (curHeight < maxHeight)
//			{
//				maxHeight = curHeight; // when the height is smaller the figure is higher
//			}
//		}
//
//		//right
//
//	}



	//Point& res ;
	//for (int i = ROWS; i > 0; i--)
	//{
	//	for (int j = COLS + 2; j < 2 * COLS + 3; j++)
	//	{
	//		if (GameBoard.isValidPoint(j, i))
	//		{
	//			for (int count = 0; count < f->getSize(); count++)
	//			{
	//				Point& res = f->getBodyPos(count);// öøéëåú ìîîù àú äôåð÷öéä ùîçæéøä àú äâåó ùì äöåøä
	//				if ((GameBoard.isValidPoint(res.getX() - 1, res.gety())))
	//				{
	//					f->update(GameBoard, f->getSerial(), LEFT);
	//					break;
	//					//f.updateFigureLeft(GameBoard, f->getSerial());
	//				}
	//				else if (GameBoard.isValidPoint(res.getX() + 1, res.gety()) && GameBoard.isValidPoint(res.getX(), res.gety() + 1))
	//				{
	//					f->update(GameBoard, f->getSerial(), RIGHT);
	//					break;
	//				}
	//				break;
	//				// else if right // else if rotate // else if counterrotate
	//			}
	/*		}
		}
	}*/

void Computer::FindTheBestPlacementOfFigure(general* f, int NumPlayer)
{

	//Figure* temp = new Figure(f->getSerial(), RIGHT_PLAYER, GameBoard);
	//
	//bool res;
	//int counterDeletedLines1 =0;
	//int counterDeletedLines2 = 0;
	//int maxHeight1 ; // height of the figure in the row
	//int maxHeight2 ;
	//int curHeight , BestHeigt;
	//int BestRow ; //the placement that delete to most rows
	//int BestCol, Col1, Col2;
	//BotMovesGrade Pos[SIZE];
	// îòøê ùì 4 ùéù áå àú äîöá ùì ëì öåøä åðòùä äùîä ìòîåãä äëé èåáä ìäéåú áä ùì àåúå îöá
	// arr[0] = 3 ôåæéùï áîöá 0 áòîåãä 

	if (f->getSerial() == BOMB)
	{
		FindTheBestPlacementOfBomb(f, NumPlayer);
	}
	else
	{

		Figure* temp = new Figure(f->getSerial(), NumPlayer, GameBoard);

		bool res;
		int counterDeletedLines1 = 0;
		int counterDeletedLines2 = 0;
		int maxHeight1; // height of the figure in the row
		int maxHeight2;
		int curHeight, BestHeigt;
		int BestRow; //the placement that delete to most rows
		int BestCol, Col1, Col2;
		BotMovesGrade Pos[SIZE];


		for (int i = 0; i < SIZE; i++)
		{

			while (temp->update(GameBoard, temp->getSerial(), LEFT, 1)) {}
			//temp->print(GameBoard);
			//Sleep(100);

			Col1 = LowColOfCurrPlacement(temp);
			while (temp->update(GameBoard, temp->getSerial(), DOWN, 1)) {}
			//temp->print(GameBoard);


			counterDeletedLines1 = BestRow = HowManyDeletedLines(GameBoard, NumPlayer); //we calculate how many lines the current figure drops

			maxHeight1 = BestHeigt = calculateTheHeightOfCurrPlacement(temp); // the Height of the figure in current placement

			res = temp->update(GameBoard, temp->getSerial(), RIGHT, 1);

			while (temp->update(GameBoard, temp->getSerial(), DOWN, 1)) {
				//temp->print(GameBoard);
			}
			Col2 = LowColOfCurrPlacement(temp);


			counterDeletedLines2 = HowManyDeletedLines(GameBoard, NumPlayer);
			maxHeight2 = calculateTheHeightOfCurrPlacement(temp);
			BestCol = compareBetween2Placements(BestHeigt, maxHeight2, BestRow, counterDeletedLines2, &BestHeigt, &BestRow, Col1, Col2);


			//right
			while (temp->update(GameBoard, temp->getSerial(), RIGHT, 1))
			{
				//temp->print(GameBoard);

				Col2 = LowColOfCurrPlacement(temp);
				while (temp->update(GameBoard, temp->getSerial(), DOWN, 1)) {
					//temp->print(GameBoard);
				}

				counterDeletedLines2 = HowManyDeletedLines(GameBoard, NumPlayer);
				maxHeight2 = calculateTheHeightOfCurrPlacement(temp);
				BestCol = compareBetween2Placements(BestHeigt, maxHeight2, BestRow, counterDeletedLines2, &BestHeigt, &BestRow, BestCol, Col2);
			}
			Pos[i].Setbestcol(BestCol);
			Pos[i].SetDeletedLines(BestRow);
			Pos[i].SetHeight(BestHeigt);

			delete temp;
			Figure* temp = new Figure(f->getSerial(), NumPlayer, GameBoard);
			temp->update(GameBoard, temp->getSerial(), CLOCKWISE, 1);

		}
		delete temp;
		int besRotation = compareRotations(Pos, SIZE);

		while (f->getRotateNum() != besRotation)
		{
			f->update(GameBoard, f->getSerial(), CLOCKWISE, 1);
			f->print(GameBoard);

			Sleep(100);
		}

		while (LowColOfCurrPlacement(f) < Pos[besRotation].Getbestcol())
		{
			f->update(GameBoard, f->getSerial(), RIGHT, 1);
			f->print(GameBoard);
			Sleep(100);
		}
		while (LowColOfCurrPlacement(f) > Pos[besRotation].Getbestcol())
		{
			f->update(GameBoard, f->getSerial(), LEFT, 1);
			f->print(GameBoard);
			Sleep(100);

		}
	}
}

void Computer::FindTheBestPlacementOfBomb(general* f, int NumPlayer)
{
	int maxExplodedCounter;
	int currExplodedCounter;
	int bestCol;
	int currCol;
	Bomb* tempBomb = new Bomb(NumPlayer, GameBoard);
	while (tempBomb->update(GameBoard, BOMB, LEFT, 2)) {}

	while (tempBomb->update(GameBoard, BOMB, DOWN, 2)) {}
	tempBomb->explodeBomb(GameBoard, 2);
	maxExplodedCounter = tempBomb->getExplodeNum();
	bestCol = tempBomb->getBodyPos()->getX();

	tempBomb->update(GameBoard, tempBomb->getSerial(), RIGHT, 2);
	while (tempBomb->update(GameBoard, BOMB, DOWN, 2)) {}

	tempBomb->explodeBomb(GameBoard, 2);

	currExplodedCounter = tempBomb->getExplodeNum();
	currCol = tempBomb->getBodyPos()->getX();

	CompareFuncForBomb(&maxExplodedCounter, currExplodedCounter, &bestCol, currCol);

	while (tempBomb->update(GameBoard, BOMB, RIGHT, 2))
	{
		while (tempBomb->update(GameBoard, BOMB, DOWN, 2)) {}
		tempBomb->explodeBomb(GameBoard, 2);

		currExplodedCounter = tempBomb->getExplodeNum();
		currCol = tempBomb->getBodyPos()->getX();

		CompareFuncForBomb(&maxExplodedCounter, currExplodedCounter, &bestCol, currCol);
	}

	delete tempBomb;

	while (bestCol > f->getBodyPos()->getX())
	{
		f->update(GameBoard, BOMB, RIGHT, 2);
		f->print(GameBoard);
		Sleep(100);
	}
	while (bestCol < f->getBodyPos()->getX())
	{
		f->update(GameBoard, BOMB, LEFT, 2);
		f->print(GameBoard);
		Sleep(100);
	}
}

void Computer::CompareFuncForBomb(int* maxExplodedNum, int currExplodedNum, int* bestcol, int col)
{
	if (currExplodedNum > *maxExplodedNum)
	{
		*maxExplodedNum = currExplodedNum;
		*bestcol = col;
	}
}

int Computer::compareRotations(BotMovesGrade* position, int size)
{
	int maxHeight = position[0].GetHeight();
	int bestRows = position[0].GetDeletedLines();
	int bestCol = position[0].Getbestcol();
	int bestRotation = 0;

	for (int i = 1; i < size; i++)
	{

		bestRotation = compareBetween2Placements(maxHeight, position[i].GetHeight(), bestRows, position[i].GetDeletedLines(), &maxHeight, &bestRows, bestRotation, i);
	}
	return bestRotation;
}

int Computer::HowManyDeletedLines(Board& board, int NumPlayer) const//we calculate how many lines the current figure drops
{
	int counterDeletedLines = 0;
	for (int i = ROWS; i > 0; i--)
	{
		if (board.IsFullRow(i, NumPlayer))
		{
			counterDeletedLines++;
		}

	}
	return counterDeletedLines;
}

int Computer::calculateTheHeightOfCurrPlacement(general* f) const
{
	Point* body = f->getBodyPos();
	int maxHeight; // height of the figure in the row
	int curHeight;

	for (int j = 0; j < 4; j++) // we calculate the hight of the figure
	{
		curHeight = body[j].gety();
		if (j == 0)
		{
			maxHeight = curHeight;
		}
		if (curHeight < maxHeight)
		{
			maxHeight = curHeight; // when the height is smaller the figure is higher
		}

	}
	return maxHeight;
}

int Computer::LowColOfCurrPlacement(general* f)
{
	Point* body = f->getBodyPos();
	int currCol, lowCol;
	for (int i = 0; i < 4; i++)
	{
		currCol = body[i].getX();
		if (i == 0)
		{
			lowCol = currCol;
		}
		if (currCol < lowCol)
		{
			lowCol = currCol;
		}
	}
	return lowCol; // the col that appear in the most left side
}
int Computer::compareBetween2Placements(int maxHeight1, int maxHeight2, int numDeletedRows1, int numDeletedRows2, int* BestHeight, int* BestRow, int Col1, int Col2)
{
	if (maxHeight1 > maxHeight2)
	{
		*BestHeight = maxHeight1;
	}
	else if (maxHeight1 < maxHeight2)
	{
		*BestHeight = maxHeight2;
	}
	if (numDeletedRows1 > numDeletedRows2)
	{
		*BestRow = numDeletedRows1;
	}
	else if (numDeletedRows1 < numDeletedRows2)
	{
		*BestRow = numDeletedRows2;
	}
	if (*BestRow == numDeletedRows1 && *BestHeight == maxHeight1)
	{
		return Col1;
	}
	else if (*BestRow == numDeletedRows2 && *BestHeight == maxHeight2)
	{
		return Col2;
	}
	else if (*BestRow == numDeletedRows1 && *BestHeight != maxHeight1)
	{
		return Col1;
	}
	else if (*BestRow == numDeletedRows2 && *BestHeight != maxHeight2)
	{
		return Col2;
	}

}