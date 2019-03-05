#include "Tree.hpp"


//-- Vertex----------------------------------------(struct)

Vertex::Vertex(int x, int y, char d)
{
	this->x = x;
	this->y = y;
	this->d = d;
	this->parent = nullptr;
}

Vertex::~Vertex() 
{
	while (!children.empty())
	{
		delete children.front();
		children.pop_front();
	}
}

void Vertex::addChild(Vertex* V)
{
	V->parent = this;
	children.push_back(V);
}

//--Tree-------------------------------------------

Tree :: Tree() {
}

Tree::~Tree()
{
	delete root;
}