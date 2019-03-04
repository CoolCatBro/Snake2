#include "Food.hpp"


Food::Food(Level* level)
	 :Node(level,"food"),level(level)
{	
}

//check for command flag and then create food
void Food::createFood()
{
	if (level->addFood)
	{
		int x = rand() % GAME_WIDTH;
		int y = rand() % GAME_HEIGHT;
		while ((scene->gameEng.moveXY(x, y) && scene->gameEng.readCh() != ' '))
		{
			x = rand() % GAME_WIDTH;
			y = rand() % GAME_HEIGHT;
		}
		level->food = pair<int, int>(x, y);
		level->addFood = false;
	}
}

void Food::load()
{
	//Dependency from different layer
}

void Food::render(double& dt)
{
	createFood();
	scene->gameEng.mvprintCh(level->food.first, level->food.second, FOOD);
}