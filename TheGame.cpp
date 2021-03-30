
#include "TheGame.h"
#include "Board.h"
#include "Figure.h"
#include <conio.h>
#include <iostream>



void TheGame::StartGame()//TODO- àîåø ìäéåú îåãôñ ìåç åìäúçéì îùç÷
{
	char key_char=0;
	
	while (key_char != ESC&& _getch()!=EXIT)
	{
		if (_kbhit)
		{
			key_char = _getch();
		}

		else if (key_char == PAUSE)
		{
			system("pause"); //not sure
		}

		else if (key_char == INSTRUCTIO_KEYS)
			ShowInstructions();
		else if (key_char == START)
		{
			while ((!_kbhit()) || ((_getch() != EXIT )&& (_getch( )!= ESC)))
			{
				gotoxy(7, 1); 
				f.printFigure();//אמור להדפיס את הצןרה הראשונה בלוח אחד
				gotoxy(13 + 6, 1);//ובלוח השני
				f.printFigure();
			}
		}

	}
}

void TheGame::drawFigure(int typeOfFigure)
{
	int randFigure= rand() % RAND;
	switch (randFigure)
	{
	case 0:
	{
		f.SetSerialNum(SHAPES::l);
		f.initFigureBySerialNum();
		break;

	}
	case 1:
	{
		f.SetSerialNum(SHAPES::L);
		f.initFigureBySerialNum();
		break;
	}
	case 2:
	{
		f.SetSerialNum(SHAPES::J);
		f.initFigureBySerialNum();
		break;
	}
	case 3:
	{
		f.SetSerialNum(SHAPES::O);
		f.initFigureBySerialNum();
		break;
	}
	case 4:
	{
		f.SetSerialNum(SHAPES::S);
		f.initFigureBySerialNum();
		break;
	}
	case 5:
	{
		f.SetSerialNum(SHAPES::Z);
		f.initFigureBySerialNum();
		break;
	}
	case 6:
	{
		f.SetSerialNum(SHAPES::RT);
		f.initFigureBySerialNum();
		break;
	}
	}
}


void TheGame::ContinueGame()//TODO- ìäîùéê àú äîùç÷ îäî÷åí ùáå òöøðå
{
	system("cls");
}
void TheGame::ShowInstructions()
{
	std::cout << "Goal: You have to make full horizontal lines with the different shaped blocks that fall into the game area.Full lines will then disappear and Increases the chance of winning the game" << endl;
	std::cout << "The player whose board is filled first loses, the other player wins";
	std::cout << "Controls:" << endl << "Player 1(The left player):" << endl << "'a' or 'A' key : move block to the left" << endl << "'d' or 'D' key : move block to the right" << endl << "'s' or 'S' key : rotate block clockwise" << endl << "'w' or 'W' key : rotate block counterclockwise" << endl << "'x' or 'X' key : move block down";
	std::cout << "Controls:" << endl << "Player 2(The right player):" << endl << "'j' or 'J' key : move block to the left" << endl << "'l' or 'L' key : move block to the right" << endl << "'k' or 'K' key : rotate block clockwise" << endl << "'i' or 'I' key : rotate block counterclockwise" << endl << "'m' or 'M' key : move block down";
}
void TheGame::ExitGame()
{
	system("cls");//not sure
	

}

void TheGame::ChooseOption()
{
	/*int menuKey;
	if (_kbhit())
	{
		menuKey = _getch();
	}*/
	if (_getch() == START)//TODO
		StartGame();
	if (_getch() == PAUSE)//conitnue game cancel esc
	{
		system("pause");
		//ContinueGame(); // TODO
	}
		
	if (_getch() == INSTRUCTIO_KEYS)
		ShowInstructions();
	if (_getch() == EXIT)
	{
		//break;
		ExitGame();
	}
		
}