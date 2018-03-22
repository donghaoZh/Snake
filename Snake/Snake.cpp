#include"Snake.h"


extern const int En_length;

Snake::Snake() {};

Snake::Snake(SPosition Snake_head[]): Score(0), PastDirection(80)
{

	for (int i = 0; i < sizeof(Snake_head); i++)
	{
		Snake_Vector.push_back(Snake_head[i]);
	}
Snack_Tail = Snake_Vector[Snake_Vector.size() - 1];
}


void Snake::JudgeDirection(int MyDirection)
{
	//if (_kbhit() != 0)//检查当前是否有键盘输入
	//{
	//	int MyDirection = NULL;
	//	MyDirection = _getch();
	//	if (MyDirection == 224 || MyDirection == 0)
	//		MyDirection = _getch();
	if (MyDirection == 72 || MyDirection == 80 || MyDirection == 75 || MyDirection == 77)
		PastDirection = MyDirection;
	//}




	unsigned int i;
	Snack_Tail = Snake_Vector[Snake_Vector.size() - 1];
	for (i = 0; i < Snake_Vector.size() - 1; i++)
	{
		Snake_Vector[Snake_Vector.size() - i - 1] =
			Snake_Vector[Snake_Vector.size() - i - 2];
	}
	//Snack_Tail = Snake_Vector[Snake_Vector.size() - 1];
	switch (PastDirection)
	{
	case 72: 		Snake_Vector[0].SetY(Snake_Vector[0].GetY() - 1); break;//上
	case 80:		Snake_Vector[0].SetY(Snake_Vector[0].GetY() + 1); break;//下
	case 75:		Snake_Vector[0].SetX(Snake_Vector[0].GetX() - 1); break;//左
	case 77:		Snake_Vector[0].SetX(Snake_Vector[0].GetX() + 1); break;//右
	}
}


void Snake::JudgeDirection(int MyDirection, mode modetry)
{
	if (modetry = ModeTwo)
	{
		//if (_kbhit() != 0)//检查当前是否有键盘输入
		//{
		//	int MyDirection = NULL;
		//	MyDirection = _getch();
		if (MyDirection == 119 || MyDirection == 115 || MyDirection == 97 || MyDirection == 100)
			PastDirection = MyDirection;
		//}

		Snack_Tail = Snake_Vector[Snake_Vector.size() - 1];

		unsigned int i;
		for (i = 0; i < Snake_Vector.size() - 1; i++)
		{
			Snake_Vector[Snake_Vector.size() - i - 1] =
				Snake_Vector[Snake_Vector.size() - i - 2];
		}

		if (80 == PastDirection) PastDirection = 115;
		switch (PastDirection)
		{
		case 119: 		Snake_Vector[0].SetY(Snake_Vector[0].GetY() - 1); break;//上w
		case 115:		Snake_Vector[0].SetY(Snake_Vector[0].GetY() + 1); break;//下s
		case 97:		Snake_Vector[0].SetX(Snake_Vector[0].GetX() - 1); break;//左a
		case 100:		Snake_Vector[0].SetX(Snake_Vector[0].GetX() + 1); break;//右d
		}
	}
}


void Snake::JudgeError(bool &JudgeOne)
{
	if (Snake_Vector[0].GetX() >= En_length + 1 || Snake_Vector[0].GetX() <= 0 ||
		Snake_Vector[0].GetY() >= En_length + 1 || Snake_Vector[0].GetY() <= 0) JudgeOne = TRUE;
	for (unsigned int i = 1; i < Snake_Vector.size(); i++)
	{
		if (Snake_Vector[0] == Snake_Vector[i])
		{
			JudgeOne = TRUE;
			break;
		}
	}
}


void Snake::JudgeError(Snake SnakeTwo, bool &JudgeOne, bool &JudgeTwo)
{
	int S_Error = 0;
	if (Snake_Vector[0].GetX() >= En_length + 1 || Snake_Vector[0].GetX() <= 0 ||
		Snake_Vector[0].GetY() >= En_length + 1 || Snake_Vector[0].GetY() <= 0) JudgeOne = TRUE;
	if (SnakeTwo.Snake_Vector[0].GetX() >= En_length + 1 || SnakeTwo.Snake_Vector[0].GetX() <= 0 ||
		SnakeTwo.Snake_Vector[0].GetY() >= En_length + 1 || SnakeTwo.Snake_Vector[0].GetY() <= 0) JudgeTwo = TRUE;
	for (unsigned int i = 1; i < Snake_Vector.size(); i++)
	{
		if (Snake_Vector[0] == Snake_Vector[i])
		{
			JudgeOne = TRUE;
			break;
		}
	}
	for (unsigned int i = 1; i < Snake_Vector.size(); i++)
	{
		if (SnakeTwo.Snake_Vector[0] == Snake_Vector[i])
		{
			JudgeTwo = TRUE;
			break;
		}
	}

	for (unsigned int i = 1; i < SnakeTwo.Snake_Vector.size(); i++)
	{
		if (SnakeTwo.Snake_Vector[0] == SnakeTwo.Snake_Vector[i])
		{
			JudgeTwo = TRUE;
			break;
		}
	}
	for (unsigned int i = 0; i < SnakeTwo.Snake_Vector.size(); i++)
	{
		if (Snake_Vector[0] == SnakeTwo.Snake_Vector[i])
		{
			JudgeOne = TRUE;
			break;
		}
	}
}



void Snake::add_Snack(food &FoodPosition)
{
	if (Snake_Vector[0] == FoodPosition.GetFPos())
	{
		Snake_Vector.push_back(Snack_Tail);
		Score++;
		FoodPosition.Eat_Rand();
	}
}

int Snake::GetScore()
{
	return Score;
}


Snake::~Snake(){}

void Snake::back_Death()
{
	PastDirection;
	unsigned int i;
	for (i = 0; i < Snake_Vector.size() - 1; i++)
	{
		Snake_Vector[i] =Snake_Vector[i+1];
	}
	Snake_Vector[Snake_Vector.size()-1] = Snack_Tail;
}