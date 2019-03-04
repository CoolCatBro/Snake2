// Layer for food level and maze

#pragma once

#include "Engine/SceneGraph.hpp"
#include "Engine/Globals.hpp"
#include "Engine/GameManager.hpp"

#include <utility>

using std::pair;

class Level : public Layer
{

public:
	GameManager* gm;

// can acess by nodes

//Food------------------
	pair<int, int> food;
	bool addFood;
//------------------------

public:

	Level(GameManager *gm);

};