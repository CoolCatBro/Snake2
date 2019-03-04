// Graph for bfs and path finding purposes

#pragma once

#include <list>

using std::list;

struct Vertex
{
	int x,y;
	list<Vertex*> Edges;


	Vertex(int x, int y);

	void clear();
	void addEdge(Vertex* V);
};

class Graph
{
public:

	list<Vertex*> Edges;
	
	void addAdj(Vertex* V);
	void clear();
};

// notes 
// clear function does not delete memory from heap
// use clear if you want to reload the graph