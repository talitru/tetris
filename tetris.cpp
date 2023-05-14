#include "headerFiles/tetris.h"

#include <conio.h>

void tetris::ChooseGame() // ���� ������ ������ �� ����� ��� ��� �� ������� �����
{
	char key_char = 0;
	TheGame* game = nullptr;
	while (1)
	{
		if (_kbhit())
		{
			key_char = _getch();
			if (!game  && key_char == INSTRUCTIO_KEYS)
			{
				game->getMenuInstructions();
			}
			if (key_char == STARTHvsH)
			{
				game = new HumanVsHuman();
				game->RunGame();
				
			}
			else if (key_char == STARTHvsC)
			{
				game = new HumanVsComputer();
				game->RunGame();
				
			}
			else if (key_char == STARTCvsC)
			{
				game = new ComputerVsComputer();
				game->RunGame();
			}
			
			delete game;

		}
	}
}

