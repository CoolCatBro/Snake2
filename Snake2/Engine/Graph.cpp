#include "Graph.hpp"


//-- Vertex----------------------------------------(struct)

Vertex::Vertex(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Vertex::addEdge(Vertex* V)
{
	Edges.push_back(V);
}

void Vertex::clear()
{
	while (!Edges.empty())
	{
		Edges.front()->clear();
		Edges.pop_front();
	}
}

//--Graph-------------------------------------------

void Graph::addAdj(Vertex *V)
{
	Edges.push_back(V);
}

void Graph::clear()
{
	while (!Edges.empty())
	{
		Edges.front()->clear();
		Edges.pop_front();
	}
}