// it extends scene 
// The main game handler

#pragma once

#include "SceneGraph.hpp"
#include "Globals.hpp"

#include <ctime>

class GameManager : public Scene
{
	clock_t time;   // current time (CLOCK CYCLES CPU)
	double dt;		// time passed

public:

	int score,lives;

	GameManager(int width,int height);
	void timer();
	void render();
};