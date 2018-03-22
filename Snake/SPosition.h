#pragma once
#include"Global.h"

class SPosition
{
public:
	SPosition(int x, int y);
	SPosition();
	friend bool operator == (SPosition &Position1, SPosition &Position2);
	int GetX();
	int GetY();
	void SetX(int myX);
	void SetY(int myY);
private:
	int X, Y;
};