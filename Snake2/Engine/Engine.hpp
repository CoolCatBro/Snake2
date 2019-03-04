/* Engine Implements WriteConsoleOutput function for faster console output*/
/*Double buffering technique using buffer array*/

#pragma once

#include <string>
#include <windows.h>

using std::string;

class Engine
{
	HANDLE console;
	CONSOLE_SCREEN_BUFFER_INFO csbinfo;
	COORD  cursorPosition = { 0,0 };    // buffer cursor position
	CHAR_INFO* buffer;

public:
	
	//bsize is size of char array
	int bsize;
	int screen_width, screen_height;

	//Engine():fullscreen
	//Engine(...):proper size window
	Engine();
	Engine(int screen_width, int screen_height);

	//Move to a position in buffer
	int     moveXY(int x, int y);

	//Print character at a position in buffer
	void    printCh(char ch);

	//Print string at position in buffer
	void    printW(string str);

	//Move and print
	void    mvprintCh(int x, int y, char ch);
	void    mvprintW(int x, int y, string str);
	
	//Read character at buffer cursor positon
	char	readCh();

	//Refresh = print the buffer
	//clear the buffer
	void    refresh();
	void    clear();
};