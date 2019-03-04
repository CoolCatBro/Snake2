#include "Snake.hpp"

//Snake-----------------------------------------------------------

Snake::Snake(Level *level) 
	  :Node(level,"snake"),level(level)
{
	x = 30;
	y = 10;
	bodyLength = 2;
	direction = 'd';

	for (int i = 1; i <= bodyLength; i++)
	{
		body.push_back(pair<int, int>(x - i, y));
	}
}

void Snake::load()
{
	//Dependency from other layers
}

void Snake::eat()
{
	level->gm->score++;
	bodyLength++;
	body.push_back(pair<int, int>(-1, -1));
}

void Snake::move()
{
  if(!collide())
  {
	
    if(level->food.first == x && level->food.second == y)
    {
      eat();
	  level->addFood = true;
    }

    if(direction==UP)
   	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x, y--));
	}
    if(direction==LEFT)
	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x--, y));
	}
	if(direction==DOWN)
	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x, y++));
	}
	if(direction==RIGHT)
	{
	  body.pop_back();
	  body.push_front(pair<int, int>(x++, y));
	}
 }
}

void Snake::setDirection(char ch)
{
  if(direction==UP && ch==DOWN || direction==DOWN && ch==UP  || direction==RIGHT && ch==LEFT  || direction==LEFT && ch==RIGHT )
  return;
  if(ch==UP || ch==LEFT || ch==DOWN || ch==RIGHT)
  direction=ch;
}

bool Snake::collide()
{
  if ((scene->gameEng.moveXY(x,y) && scene->gameEng.readCh() == WALL)  
	  || (find(body.begin(),body.end(),pair<int,int>(x,y)) != body.end()) )
  return true;
  else
  return false;
}

void Snake::reset()
{
	x = 30;
	y = 10;
	body.clear();
	bodyLength = 2;
	for (int i = 1; i <= bodyLength; i++)
	{
		body.push_back(pair<int, int>(x - i, y));
	}
	direction = 'd';
}

void Snake::render(double& dt)
{
  for(int i=0;i<bodyLength;i++)
  {
       scene->gameEng.mvprintCh(body[i].first, body[i].second,SNAKE);
  }
       scene->gameEng.mvprintCh(x,y, HEAD);
}
