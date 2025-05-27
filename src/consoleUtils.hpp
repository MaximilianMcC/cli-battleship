/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) [2025] Media Design School
File Name : consoleUtils.hpp
Description : Colors, formatting, and cursor positions
Author : Maximilian McCarthy, MDS
Mail : maximilian.mccarthy@mds.ac.nz
**************************************************************************/

#include <iostream>
#include <windows.h>
#include "vector2.hpp"

#pragma once

class ConsoleUtils
{
public:

	// Constants
	struct Color
	{
		static constexpr const char* Reset = "\x1b[0m";
		static constexpr const char* White = "\x1b[37m";
		static constexpr const char* Red = "\x1b[31m";
		static constexpr const char* BrightBlack = "\x1b[90m";
		static constexpr const char* BlackBackground = "\x1b[40m";
	};

	static void ClearScreen()
	{
		COORD coordScreen = { 0, 0 };
		DWORD cCharsWritten;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD dwConSize;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

		FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
		SetConsoleCursorPosition(hConsole, coordScreen);
	}

	static void GotoXY(int x, int y)
	{
		COORD point;
		point.X = x;
		point.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
	}

	static void GotoXY(Vector2 position)
	{
		GotoXY(position.X, position.Y);
	}

	static int getConsoleWidth()
	{
		CONSOLE_SCREEN_BUFFER_INFO console;
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(consoleHandle, &console);
		return console.dwSize.X;
	}

	static int getConsoleHeight()
	{
		CONSOLE_SCREEN_BUFFER_INFO console;
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		
		GetConsoleScreenBufferInfo(consoleHandle, &console);
		return console.dwSize.Y;
	}

	static int getCursorX()
	{
		CONSOLE_SCREEN_BUFFER_INFO console;
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(consoleHandle, &console);
		return console.dwCursorPosition.X;
	}

	static int getCursorY()
	{
		CONSOLE_SCREEN_BUFFER_INFO console;
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

		GetConsoleScreenBufferInfo(consoleHandle, &console);
		return console.dwCursorPosition.Y;
	}

	static void hideCursor()
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;

		GetConsoleCursorInfo(console, &cursorInfo);
		cursorInfo.bVisible = false;
		SetConsoleCursorInfo(console, &cursorInfo);
	}

	static void showCursor()
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO cursorInfo;
		
		GetConsoleCursorInfo(console, &cursorInfo);
		cursorInfo.bVisible = true;
		SetConsoleCursorInfo(console, &cursorInfo);
	}

	static int utfStringLength(std::string string)
	{
		size_t length = 0;

		// Loop through the string until we 
		for (size_t i = 0; i < string.size(); i++)
		{
			// Unicode stuff has more than one byte, so
			// we check all the bytes and only add to the
			// count if its a leading byte (start of a char)
			if ((string[i] & 0xC0) != 0x80) length++;
		}
		
		return length;
	}

	static void centreText(std::string text)
	{
		GotoXY((getConsoleWidth() - utfStringLength(text)) / 2, getCursorY());
		std::cout << text;
	}

};