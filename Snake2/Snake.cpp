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

	visited = new bool*[GAME_HEIGHT];
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		visited[i] = new bool[GAME_WIDTH];
	}
}

void Snake::load()
{
	//Dependency from other layers
}

void Snake::_findPath() 
{
	deque<Vertex*> que;
	
	for (int i = 0; i < GAME_HEIGHT; i++)
	{
		for (int j = 0; j < GAME_WIDTH; j++)
		{
			visited[i][j] = false;
		}
	}

	gr = new Tree();
	gr->root = new Vertex(x, y,'\0');
	Vertex* end = nullptr;
	bool found = false;

	que.push_back(gr->root);
	visited[y][x] = true;

	while (!que.empty())
	{
		int rx = que.front()->x , ry = que.front()->y;

		if (rx == level->food.first && ry == level->food.second)
		{
			end = que.front();
			found = true;
			break;
		}
		else
		{
			if (_getNeighbour(rx + 1,ry))
			{
				visited[ry][rx + 1] = true;
				Vertex* temp = new Vertex(rx + 1, ry, RIGHT);
				que.front()->addChild(temp);
				que.push_back(temp);
			}

			if (_getNeighbour(rx - 1, ry))
			{
				visited[ry][rx - 1] = true;
				Vertex* temp = new Vertex(rx - 1, ry, LEFT);
				que.front()->addChild(temp);
				que.push_back(temp);
			}

			if (_getNeighbour(rx, ry + 1))
			{
				visited[ry + 1][rx] = true;
				Vertex* temp = new Vertex(rx, ry + 1, DOWN);
				que.front()->addChild(temp);
				que.push_back(temp);
			}

			if (_getNeighbour(rx, ry - 1))
			{
				visited[ry - 1][rx] = true;
				Vertex* temp = new Vertex(rx, ry - 1,UP);
				que.front()->addChild(temp);
				que.push_back(temp);
			}
		}

		que.pop_front();
	}

	if (found) 
	{
		while (end->d != '\0')
		{
			path.push_front(end->d);
			end = end->parent;
		}
	}
	delete gr;
	que.clear();
}

bool Snake::_getNeighbour(int rx, int ry)
{
	if ((rx >= 0 && rx < GAME_WIDTH) && (ry >= 0 && ry < GAME_HEIGHT) 
		&& !visited[ry][rx] 
		&& scene->gameEng.moveXY(rx, ry) 
		//&& (scene->gameEng.readCh() == ' ' || scene->gameEng.readCh() == FOOD)
		)
	{
		return true;
	}
	else
		return false;
}

void Snake::eat()
{
	level->gm->score++;
	bodyLength++;
	body.push_back(pair<int, int>(-1, -1));
}

void Snake::move()
{
  if(true)//!collide())
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

void Snake::moveAI() 
{
	if (!path.empty())
	{
		direction = path.front();
		move();
		path.pop_front();
	}
	else
	{
		direction = '\0';
		move();
		_findPath();
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
