#pragma once

#include "Engine/SceneGraph.hpp"
#include "Engine/Globals.hpp"
#include "Engine/GameManager.hpp"
#include "Engine/Tree.hpp"

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
	deque <pair<int, int> > body;
	
	bool **visited;
	Tree* gr;

	// Snake dependencies
	Level* level;

public:

	// snake properties visible to everyone
	int x,y;         
	int bodyLength;
	char direction;

private:

	void _findPath();
	bool _getNeighbour(int rx,int ry);
	deque<char> path;

public:
	
	int score;

	Snake(Level *level);

	//overwrite these functions of Node
	void load();
	void render(double& dt);

	//snake owns method
	void eat();
	void move();
	void moveAI();          //Using bfs
	void setDirection(char);
	bool collide();
	void reset();
};
