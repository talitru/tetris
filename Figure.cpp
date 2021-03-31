#include "Figure.h"

void Figure::Rotate()
{
	//if(direction=='w')
	// אם המשתמש הכניס למעלה- הצורה מסתובבת, בשאר הכיוונים נשארת אותו דבר
}
void Figure::RightOrLeftOrdown()
{

}
void Figure::printFigure(Point& p)
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if ((FigureBody[i][j] == 1)&& !p.getIsBusy())
				cout << '#';
			else
				cout << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void Figure::initFigureBySerialNum()
{
	switch (serial_num_of_figure) //1-7
	{
	case SHAPES::l:
	{
		for (int i = 0; i < SIZE; i++)   

			for (int j = 0; j < SIZE; j++)
			{
				if (i == 0)
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
			}
		break;

	}

	case SHAPES::L:
	{
		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)
			{
				if ((i == 1 && j != 0) || (i == 0) && (j == 1))
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
	        }
		break;
	}
	case SHAPES::J:
	{
		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)
			{
				if ((i == 1 && j != 0) || (i == 0 && j == 3))
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
			}
		break;
	}
	case SHAPES::O:
	{
		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)
			{
				if ((i == 0 && j != 0 && j != 3) || (i == 1 && j != 0 && j != 3))
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
			}
		break;
	}
	case SHAPES::Z:
	{
		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)
			{
				if ((i == 0 && j != 0 && j != 3) || (i == 1 && j != 0 && j != 1))
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
			}
		break;
	}


	case SHAPES::S:
	{
		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)
			{
				if ((i == 0) && (j == 2 || j == 3) || (i == 1) && (j == 1 || j == 2))
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
			}
		break;
	}

	case SHAPES::RT:
	{
		for (int i = 0; i < 4; i++)

			for (int j = 0; j < 4; j++)
			{

				if ((i == 0 && j == 2) || (i == 1 && j != 0))
					FigureBody[i][j] = 1;
				else
					FigureBody[i][j] = 0;
			}
		break;
	}

}
	
}

void Figure::deleteFigure()
{

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (FigureBody[i][j] == 1)
				cout << ' ';
			/*else
				cout << ' ';*/
		}
		cout << endl;
	}
}

void Figure::setBoard(Board* b1)//לא יודעת אם באמת צריך
{
	b = b1;
}