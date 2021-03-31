#pragma once
#include "gotoxy.h"

class Point
{
	int x;
	int y;
	bool IsBusy;
	char ch; //the sign of the point
public:
	//ctor
	Point() {};
	Point(int _x, int _y, bool _IsBusy = true, char _ch = '*') :x(_x), y(_y), IsBusy(_IsBusy), ch(_ch) {};

	//setters

	void SetPoint(int _x, int _y, bool _IsBusy, char _ch)
	{
		int x = _x;
		int y = _y;
		bool IsBusy = _IsBusy;
		char ch = _ch;
	};

	//getters
	void draw() const
	{
		gotoxy(x, y);
		cout << ch;
	}
	int getX()const
	{
		return x;
	}
	int gety()const
	{
		return y;
	}
	char getFigure()const
	{
		return ch;
	}
	bool getIsBusy()const
	{
		return IsBusy;
	}

};
