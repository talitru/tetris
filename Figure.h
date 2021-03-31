#pragma once
#include "Board.h"
#include <iostream>

enum SHAPES { l = 1, L = 2, J = 3, O = 4, Z = 5, S = 6, RT = 7 };//RT=reversed T=  *
																	 //=              *** 

class Figure                                        
{
	enum { SIZE = 4 };
	char FigureBody[SIZE][SIZE]; //7 figures ****  **   *       *     **     *     **
	////////////////////////////////// **   ***   ***    **     ***     **
	char direction;
	int serial_num_of_figure=0;
	
	Board* b; //לא יודעת אם באמת צריך
public:
	//enum SHAPES { l = 1, L = 2, J = 3, O = 4, Z = 5, S = 6, RT = 7 };//RT=reversed T=  *
	                                                                 //=              *** 

	//ctor
	Figure()
	{
		
	};
	void SetSerialNum(int num) { serial_num_of_figure = num; };
	int GetSerialNum() const { return serial_num_of_figure; };
	void initFigureBySerialNum();
	void printFigure(Point& p);
	void deleteFigure();
	void Rotate();//Rotate is up- kbhit בלחיצה ימינה אני צריכה להזיז את הקורדינטות ימינה
	void RightOrLeftOrdown();
	
	void setBoard(Board* b1);//לא יודעת אם באמת צריך

};