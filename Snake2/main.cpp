#include "Level.hpp"
#include "Snake.hpp"
#include "Food.hpp"

#include<conio.h>

int main()
{
	//Scene
	GameManager gm(GAME_WIDTH,GAME_HEIGHT+1);

	//Layers
	Level* level = new Level(&gm);

	//Nodes
	Snake* snake = new Snake(level);
	Food* food = new Food(level);

	gm.load();
	gm.render();
	gm.gameEng.refresh();
	
	char key='\0';
	while (1)
	{
		Sleep(0);
		
		//if(_kbhit())
		//key = _getch();
		//snake->setDirection(key);
		//snake->move();

		gm.render();
		snake->moveAI();
		gm.gameEng.refresh();
		gm.gameEng.clear();
	}
	return 0;
}