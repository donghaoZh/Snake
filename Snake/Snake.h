#pragma once
#include"food.h"



class Snake
{
public:
	Snake();
	Snake(SPosition Snake_head[]);
	void JudgeDirection(int MyDirection);
	void JudgeDirection(int MyDirection , mode modetry);
	void JudgeError(bool &JudgeOne);
	void JudgeError(Snake SnakeTwo, bool &JudgeOne, bool &JudgeTwo);
	void add_Snack(food &FoodPosition);
	int GetScore();
	void back_Death();
	~Snake();

	vector<SPosition> Snake_Vector;
private:
	int Score;
	int PastDirection;
	SPosition Snack_Tail;
};