#pragma once

#include "Engine/SceneGraph.hpp"
#include "Engine/Globals.hpp"

#include "Level.hpp"

class Food : public Node
{
	Level* level;
public:
	Food(Level* level);

	void createFood();

	void load();
	void render(double& dt);
};

