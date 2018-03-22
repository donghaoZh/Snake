#include"map.h"



int main()
{
	int difficulty;
	cout << "请选择难度:1.困难；2.中等；3.简单"<<endl;
	cin >> difficulty;
	SPosition Snake_head[4] = { SPosition(1,4),SPosition(1,3),SPosition(1,2),SPosition(1,1) };
	Snake SnakeOne(Snake_head);
	SPosition Snake_headTwo[4] = { SPosition(En_length  , 4), SPosition(En_length  , 3) ,
		SPosition(En_length  , 2) ,SPosition(En_length  , 1) };
	Snake SnakeTwo(Snake_headTwo);
	Snake *PSnakeOne = new Snake(SnakeOne), *PSnakeTwo = new Snake(SnakeTwo);


	food FoodOne;
	list<food> FoodDeath;//game over的snake
	map AllMap;

	bool JudgeOne = FALSE;
	bool JudgeTwo = FALSE;
	int death = 0;
	mode Mode = ModeOne;
	int score1 = 0, score2 = 0;
	int *scoreVec[2] = { &score1 ,&score2 };
	int loopNum = 1;
	int accNum = 1;


	while (1)
	{
		AllMap.IntMap();
		if (Mode == ModeOne)
		{
			PSnakeOne->JudgeError(JudgeOne);
			if (JudgeOne)break;
			AllMap.DrawMap(*PSnakeOne);

			while (AllMap.Snack_map[FoodOne.GetFPos().GetX()][FoodOne.GetFPos().GetY()] == 1 ||
				AllMap.Snack_map[FoodOne.GetFPos().GetX()][FoodOne.GetFPos().GetY()] == 2)
				FoodOne.Eat_Rand();

			AllMap.DrawFood(FoodOne);


			AllMap.PrintSnack();
			int MyDirection = NULL;
			if (_kbhit() != 0)//检查当前是否有键盘输入
			{
				MyDirection = _getch();
				if (MyDirection == 224 || MyDirection == 0)
					MyDirection = _getch();
				else if (43 == MyDirection)
						Mode = ModeTwo;
				else if (MyDirection == 13)
				{
					while (1)
					{
						if (_kbhit() != 0)//检查当前是否有键盘输入
						{
							int pause = _getch();
							if (pause == 13)
							{
								break;
							}
						}
					}
				}
			}

			PSnakeOne->JudgeDirection(MyDirection);
			PSnakeOne->add_Snack(FoodOne);
			score1 = PSnakeOne->GetScore();
			cout << "score : " << score1 << endl;
		}


		//双人模式
		else if (Mode == ModeTwo)
		{
			//判断剩余snake
			if (!JudgeOne && !JudgeTwo)
				PSnakeOne->JudgeError(*PSnakeTwo, JudgeOne, JudgeTwo);
			else if (JudgeOne && !JudgeTwo)
				PSnakeTwo->JudgeError(JudgeTwo);
			else if (!JudgeOne && JudgeTwo)
				PSnakeOne->JudgeError(JudgeOne);
			//对已失败snake的处理
			if (JudgeOne && JudgeTwo)break;
			else if (JudgeOne && !JudgeTwo && 0 == death)
			{
				PSnakeOne->back_Death();
				for (auto i : PSnakeOne->Snake_Vector)
				{
					FoodDeath.push_back(i);
				}
				delete PSnakeOne;
				PSnakeOne = nullptr;
				death = 1;
			}
			else if (!JudgeOne && JudgeTwo && 0 == death)
			{
				PSnakeTwo->back_Death();
				for (auto i : PSnakeTwo->Snake_Vector)
				{
					FoodDeath.push_back(i);
				}
				delete PSnakeTwo;
				PSnakeTwo = NULL;
				death = 1;
			}

			//填写矩阵
			if (PSnakeOne)
			{
				AllMap.DrawMap(*PSnakeOne);
			}
			if (PSnakeTwo)
			{

				AllMap.DrawMap(*PSnakeTwo);

			}
			AllMap.DrawMap(FoodDeath);
			while (AllMap.Snack_map[FoodOne.GetFPos().GetX()][FoodOne.GetFPos().GetY()] == 1 ||
				AllMap.Snack_map[FoodOne.GetFPos().GetX()][FoodOne.GetFPos().GetY()] == 2)
				FoodOne.Eat_Rand();
			AllMap.DrawFood(FoodOne);

			//打印*
			AllMap.PrintSnack();


			int MyDirection = NULL;
			if (_kbhit() != 0)//检查当前是否有键盘输入
			{
				MyDirection = _getch();
				if (MyDirection == 224 || MyDirection == 0)
					MyDirection = _getch();
				else if (MyDirection == 13)
				{
					while (1)
					{
						if (_kbhit() != 0)//检查当前是否有键盘输入
						{
							int pause = _getch();
							if (pause == 13)
							{
								break;
							}
						}
					}
				}
			}


			Snake *(PSnake[2]) = { PSnakeOne ,PSnakeTwo };

			for (int ps = 0; ps < 2; ps++)
			{
				if (PSnake[ps])
				{
					if (ps == 0)
						PSnake[ps]->JudgeDirection(MyDirection);
					else if (ps == 1)
						PSnake[ps]->JudgeDirection(MyDirection, Mode);
					PSnake[ps]->add_Snack(FoodOne);
					*scoreVec[ps] = PSnake[ps]->GetScore();
					if (size(FoodDeath))
					{
						for (auto i = FoodDeath.begin(); i != FoodDeath.end(); ++i)
						{
							PSnake[ps]->add_Snack(*i);
							if (*scoreVec[ps] < PSnake[ps]->GetScore())
							{
								*scoreVec[ps] = PSnake[ps]->GetScore();
								FoodDeath.erase(i);
								break;
							}

						}
					}
				}
			}
			cout << "SnakeOne : score : " << *scoreVec[0] << endl;
			cout << "SnakeTwo : score : " << *scoreVec[1] << endl;


		}
		if (loopNum > 100)
		{
			accNum++;
			loopNum /= 200;
		}
		loopNum++;
		Sleep(float(difficulty) * float(200) / float(accNum));
	}
	cout << "Game Over!" << endl;
	system("pause");
	return 0;
}
