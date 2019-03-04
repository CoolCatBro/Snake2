//Sprite is inherited from node 
/*Sprite is texture + position. Anchor point of every sprite is top-left */
//Sprite can support multiple file + animation using dt variable

#pragma once

#include "SceneGraph.hpp"

#include <fstream>
#include <cassert>

using std::ifstream;

class Sprite : public Node
{
public:

	string** frames;
	int nframe
	   ,x, y
	   ,height, width;

	Sprite(Layer*,string,int width,int height,int x,int y,int nframe=1);
	virtual ~Sprite();

	virtual void load(); 
	virtual void render(double &dt) = 0;
};