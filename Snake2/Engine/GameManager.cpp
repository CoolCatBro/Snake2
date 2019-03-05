#include "GameManager.hpp"

GameManager::GameManager(int width, int height)
	        :Scene(width,height),score(0),lives(3)
{
	srand((unsigned)std::time(nullptr));
	time = clock();
	dt = 0.0;
}

// The set value is 1.0
// timer will restart in 1 sec
void GameManager::timer() {

	dt = double(clock() - time) / CLOCKS_PER_SEC; // Calculate time 
	
	if (dt > 1.0) {                               //set value
		time = clock();
	}
}

void GameManager::render()
{
	timer();

	Scene::render(dt);

	gameEng.mvprintW(1, GAME_HEIGHT, "Score:" + std::to_string(score));
	gameEng.mvprintW(GAME_WIDTH - 8, GAME_HEIGHT, "Lives:" + std::to_string(lives));

}