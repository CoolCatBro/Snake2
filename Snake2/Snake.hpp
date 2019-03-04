#pragma once

#include "Engine/SceneGraph.hpp"
#include "Engine/Globals.hpp"
#include "Engine/GameManager.hpp"

#include "Level.hpp"

#include <deque>
#include <utility>
#include <algorithm>

using std::deque;
using std::pair;
using std::find;
using std::to_string;

class Snake: public Node
{

	bool dead = false;
	deque <pair<int, int> > body;
	
	// Snake dependencies
	Level* level;

public:

	// snake properties visible to everyone
	int x,y;         
	int bodyLength;
	char direction;

public:
	
	int score;

	Snake(Level *level);

	//overwrite these functions of Node
	void load();
	void render(double& dt);

	//snake owns method
	void eat();
	void move();
	void setDirection(char);
	bool collide();
	void reset();
};
