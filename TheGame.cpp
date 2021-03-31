
#include "TheGame.h"
#include "Board.h"
#include "Figure.h"
#include <conio.h>
#include <iostream>



void TheGame::StartGame()//TODO- àîåø ìäéåú îåãôñ ìåç åìäúçéì îùç÷
{
	char key_char=0;
	int x1 = 7,y1=1;
	int x2 = 23,y2=1;


	while ((!_kbhit()) ||key_char != EXIT || key_char != ESC)
	{
		gotoxy(x1, y1);
		randFigure();
		f.printFigure();  //אמור להדפיס את הצןרה הראשונה בלוח אחד
		Sleep(1000);
		f.deleteFigure();
	
		gotoxy(x2, y2);//ובלוח השני
		randFigure();
		f.printFigure();
		Sleep(1000);
		f.deleteFigure();

		
		y1++;
		y2++;
	}

		

	
}

void TheGame::randFigure()
{
	int randFigure= rand() % RAND; //0-6
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
	std::cout <<endl <<"Goal: You have to make full horizontal lines with the different shaped blocks that fall into the game area.Full lines will then disappear and Increases the chance of winning the game" << endl;
	std::cout << "The player whose board is filled first loses, the other player wins";
	std::cout << "Controls:" << endl << "Player 1(The left player):" << endl << "'a' or 'A' key : move block to the left" << endl << "'d' or 'D' key : move block to the right" << endl << "'s' or 'S' key : rotate block clockwise" << endl << "'w' or 'W' key : rotate block counterclockwise" << endl << "'x' or 'X' key : move block down";
	std::cout << "Controls:" << endl << "Player 2(The right player):" << endl << "'j' or 'J' key : move block to the left" << endl << "'l' or 'L' key : move block to the right" << endl << "'k' or 'K' key : rotate block clockwise" << endl << "'i' or 'I' key : rotate block counterclockwise" << endl << "'m' or 'M' key : move block down"<<endl;
}
void TheGame::ExitGame()
{
	system("cls");//not sure
	

}

void TheGame::ChooseOption()
{
	char menuKeyPressed;
	bool isPressed = false;
	while (_kbhit()|| !isPressed)
	{
		if (_kbhit())
		{	
			menuKeyPressed = _getch();

			if (menuKeyPressed == INSTRUCTIO_KEYS)
				ShowInstructions();
			else if (menuKeyPressed == START)//TODO
			{
				isPressed = true;
				StartGame();
				
			}
			//else if (menuKeyPressed == PAUSE)//conitnue game cancel esc
			//{
			//	system("pause");
			//	//ContinueGame(); // TODO
			//}

			//else if (menuKeyPressed == INSTRUCTIO_KEYS)
			//	ShowInstructions();
			//else if (menuKeyPressed == EXIT)
			//{
			//	break;
			//	//ExitGame();
			//}
		}
	}
}