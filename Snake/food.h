#pragma once
#include"SPosition.h"






class food
{
public:
	void Eat_Rand();
	food();
	food(SPosition Position);
	SPosition GetFPos();
private:
	SPosition EatPosition;
};