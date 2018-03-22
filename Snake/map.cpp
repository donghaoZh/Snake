#include"map.h"


map::map()
{
	Snack_map[En_length + 2][En_length + 2] = { 0 };
}

void map::IntMap()
{
	for (int i = 0; i < En_length + 2; i++)
	{
		for (int j = 0; j < En_length + 2; j++)
		{
			Snack_map[i][j] = 0;
		}
	}
}

void map::DrawMap(Snake DrawSnake)
{
	unsigned int S_array;

		for (S_array = 1; S_array < DrawSnake.Snake_Vector.size(); S_array++)
		{
			Snack_map[DrawSnake.Snake_Vector[S_array].GetX()][DrawSnake.Snake_Vector[S_array].GetY()] = 1;
		}
		Snack_map[DrawSnake.Snake_Vector[0].GetX()][DrawSnake.Snake_Vector[0].GetY()] = 2;
	

	for (int i = 0; i < En_length + 2; i++)
	{
		Snack_map[0][i] = 4;
		Snack_map[i][0] = 4;
		Snack_map[En_length + 1][i] = 4;
		Snack_map[i][En_length + 1] = 4;
	}
}

void map::DrawFood(food DrawFood)
{
	Snack_map[DrawFood.GetFPos().GetX()][DrawFood.GetFPos().GetY()] = 3;
}


void map::DrawMap(list<food> FoodDeath)
{
	for (auto i : FoodDeath)
	{
		Snack_map[i.GetFPos().GetX()][i.GetFPos().GetY()] = 3;
	}
}

void map::PrintSnack()
{
	
	COORD IntPosition = { 0 , 2 };
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, IntPosition);//设置输出光标位置
	int i, j;
	string star = "■" , space = " " , shead = "■", sfood = "〇";
	for (i = 0; i < En_length + 2; i++)//列y
	{
		for (j = 0; j < En_length + 2; j++)//行x
		{
			if (Snack_map[j][i] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				cout << setw(2) << star;
			}
			else if (Snack_map[j][i] == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
				cout << setw(2) << shead;
			}
			else if (Snack_map[j][i] == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				cout << setw(2) << sfood;
			}
			else if (Snack_map[j][i] == 4)
			{

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
				cout << setw(2) << star;

			}
			else
				cout << setw(2)<<space;
		}
		cout << endl;
	}
}