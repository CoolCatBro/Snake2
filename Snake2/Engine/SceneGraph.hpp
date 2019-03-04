//Scenegraph implements three classes

//Scene
/* The main class that contains layers. It is use to render the entire game context all at once*/

//Layer
/*The class that contains nodes. It groups a collection of particular type of node*/

//Node
/* The main renderable components attach to a layer*/


#pragma once

#include "Engine.hpp"

#include <vector>
#include <string>

using std::vector;
using std::string;

class Scene;
class Layer;
class Node;

class Scene
{
protected:

	vector<Layer*> Layers;

public:

	Engine gameEng;

	Scene();
	Scene(int width,int height);
	virtual ~Scene();

	// add,remove,get layer component attach to scene

	void	        addLayer(Layer* layer);       // push a layer at end
	void	        removeLayer(string id);
	Layer*	        getLayer(string id);

	// the load function should be called only once. It load external dependencies of every component
	virtual void    load();
	// it is called to render a frame ( double is the delta time for animation purposes)
	virtual void	render(double&);
};

class Layer
{
protected:

	vector<Node*> Nodes;

public:

	Scene* scene;				//Every layer has a refrence to scene

	string id;	// an id is associated to each layer for purpose of identification

	Layer(Scene* scene,string id);
	virtual ~Layer();

	// add,remove,get node component attach to scene

	void           addNode(Node* node);
	void           removeNode(string id);
	Node*          getNode(string id);

	//load called by scene, load external dependency of every node
	virtual void   load();
	virtual void   render(double&);
};

class Node
{
protected:

public:

	Scene* scene;			//Every node has a refrence to scene

	string id;

	Node(Layer* layer,string id);
	virtual ~Node();

	// These two function are to be overwriten for any node component to work

	//overwrite to set dependencies
	virtual void load() = 0;
	//overwrite to render
	virtual void render(double &dt) = 0;
};

// author notes
	/* remove function in scene and node does not delete the pointer in heap it just erase it from the list.
		addLayer push at end of list
	   The order of rendering any component will be the order of it in list*/