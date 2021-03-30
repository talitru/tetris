#pragma once
#include "Board.h"

class Player
{
	Board* b;


public:
	Player(); //ctor
	~Player()
	{
		delete b; //not sure
	}
};
