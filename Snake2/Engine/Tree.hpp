// Graph for bfs and path finding purposes

#pragma once

#include <list>

using std::list;

struct Vertex
{
	int x, y;
	char d;

	Vertex* parent;
	list<Vertex*> children;

	Vertex(int x, int y, char d);
	~Vertex();

	void addChild(Vertex* V);
};

class Tree
{
public:

	Vertex* root;

public:

	Tree();
	~Tree();
};