#include"food.h"

extern const int En_length;

food::food()
{
	Eat_Rand();
}


food::food(SPosition Position)
{
	EatPosition.SetX(Position.GetX());
	EatPosition.SetY(Position.GetY());
}

SPosition food::GetFPos()
{
	return EatPosition;
}

void food::Eat_Rand()
{

	uniform_int_distribution<unsigned> dis(1, 20);//随机数分布类
	default_random_engine RandE(unsigned int(time(0)));//随机数引擎
	EatPosition.SetX(dis(RandE));
	EatPosition.SetY(dis(RandE));

}