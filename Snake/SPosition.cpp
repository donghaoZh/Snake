#include"SPosition.h"

bool operator == (SPosition &Position1, SPosition &Position2)
{
	if (Position1.X == Position2.X && Position1.Y == Position2.Y)
		return true;
	else
		return false;
}
int SPosition::GetX() { return X; }
int SPosition::GetY() { return Y; }

void SPosition::SetX(int myX) { X = myX; }
void SPosition::SetY(int myY) { Y = myY; }

SPosition::SPosition(int x, int y):X(x),Y(y){}
SPosition::SPosition() :X(0),Y(0){}