#include "Engine.hpp"

Engine::Engine()
{
	//winAPi
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &csbinfo);

	//Calc screen_width & screen_height
	screen_width =  csbinfo.srWindow.Right - csbinfo.srWindow.Left;
	screen_height = csbinfo.srWindow.Bottom - csbinfo.srWindow.Top;

	//Allocate screen array
	bsize = screen_width * screen_height;
	buffer = new CHAR_INFO[bsize];

	for (int i = 0; i < bsize; i++)
	{
		buffer[i].Char.AsciiChar = ' ';
		buffer[i].Attributes = csbinfo.wAttributes;
	}
}

Engine::Engine(int screen_width,int screen_height)
{
	//winApi
	console = GetStdHandle(STD_OUTPUT_HANDLE);
	
	_COORD coord;
	coord.X = screen_width;
	coord.Y = screen_height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = screen_height - 1;
	Rect.Right = screen_width- 1;

	SetConsoleScreenBufferSize(console, coord);
	SetConsoleWindowInfo(console, TRUE, &Rect);
	GetConsoleScreenBufferInfo(console, &csbinfo);

	this->screen_width = screen_width;
	this->screen_height = screen_height;

	//Allocate screen array
	bsize = screen_width * screen_height;
	buffer = new CHAR_INFO[bsize];

	for (int i = 0; i < bsize; i++)
	{
		buffer[i].Char.AsciiChar = ' ';
		buffer[i].Attributes = csbinfo.wAttributes;
	}
}

int Engine::moveXY(int x, int y)
{
	if ( (x < 0 && x > screen_width) || (y < 0 && y > screen_height) )
		return 0;

	cursorPosition.X = x;
	cursorPosition.Y = y;
    return 1;
}

void Engine::printCh(char ch)
{
	buffer[cursorPosition.Y * screen_width + cursorPosition.X].Char.AsciiChar = ch;
}

void Engine::printW(string str)
{
	printCh(str[0]);
	for (unsigned int i = 1; i < str.length(); i++)
	{
		if(moveXY(cursorPosition.X+1, cursorPosition.Y))
		printCh(str[i]);
	}
}

void Engine::mvprintCh(int x, int y, char ch)
{
	if (moveXY(x, y))
		printCh(ch);
}

void Engine::mvprintW(int x, int y, string str)
{
	if (moveXY(x, y))
		printW(str);
}

char Engine::readCh()
{
	return buffer[cursorPosition.Y * screen_width + cursorPosition.X].Char.AsciiChar;
}


void Engine::refresh()
{
	COORD cstart = { 0,0 };
	COORD csize = { (SHORT)screen_width , (SHORT)screen_height };
	SMALL_RECT rect = { cstart.X,cstart.Y,csize.X,csize.Y };
	WriteConsoleOutput(console, buffer, csize, cstart, &rect);
}

void Engine::clear()
{
	for (int i = 0; i < bsize; i++)
	{
		buffer[i].Char.AsciiChar = ' ';
	}
}