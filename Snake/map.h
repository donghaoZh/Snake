#include"Snake.h"
#include"food.h"

extern const int En_length;

class map
{
public:
	map();
	void DrawMap(Snake DrawSnake);
	void DrawFood(food DrawFood);

	void DrawMap(list<food> FoodDeath);
	void PrintSnack();
	void IntMap();

	int Snack_map[En_length+2][En_length+2];
};