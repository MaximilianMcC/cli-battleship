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
 		static constexpr const char* Reset         = "\x1b[0m";
		static constexpr const char* Black         = "\x1b[30m";
		static constexpr const char* Red           = "\x1b[31m";
		static constexpr const char* Green         = "\x1b[32m";
		static constexpr const char* Yellow        = "\x1b[33m";
		static constexpr const char* Blue          = "\x1b[34m";
		static constexpr const char* Magenta       = "\x1b[35m";
		static constexpr const char* Cyan          = "\x1b[36m";
		static constexpr const char* White         = "\x1b[37m";

		static constexpr const char* BrightBlack   = "\x1b[90m";
		static constexpr const char* BrightRed     = "\x1b[91m";
		static constexpr const char* BrightGreen   = "\x1b[92m";
		static constexpr const char* BrightYellow  = "\x1b[93m";
		static constexpr const char* BrightBlue    = "\x1b[94m";
		static constexpr const char* BrightMagenta = "\x1b[95m";
		static constexpr const char* BrightCyan    = "\x1b[96m";
		static constexpr const char* BrightWhite   = "\x1b[97m";

		static constexpr const char* BgBlack       = "\x1b[40m";
		static constexpr const char* BgRed         = "\x1b[41m";
		static constexpr const char* BgGreen       = "\x1b[42m";
		static constexpr const char* BgYellow      = "\x1b[43m";
		static constexpr const char* BgBlue        = "\x1b[44m";
		static constexpr const char* BgMagenta     = "\x1b[45m";
		static constexpr const char* BgCyan        = "\x1b[46m";
		static constexpr const char* BgWhite       = "\x1b[47m";
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
		return (console.srWindow.Bottom - console.srWindow.Top) + 1;
	}

	static Vector2 getConsoleSize()
	{
		return Vector2(
			getConsoleWidth(),
			getConsoleHeight()
		);
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