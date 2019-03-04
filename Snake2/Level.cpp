#include "Level.hpp"

//Level---------------------------------------------------------

Level::Level(GameManager *gm)
	  :Layer(gm,"level"),gm(gm)
{
	addFood = true;
}