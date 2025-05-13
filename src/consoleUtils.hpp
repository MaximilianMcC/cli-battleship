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

#pragma once

class ConsoleUtils
{
public:

	// Constants
	enum Color
	{
		COLOUR_WHITE_ON_BLACK = 0, // White on Black.
		COLOUR_RED_ON_BLACK = 1, // Red on Black.
		COLOUR_GREEN_ON_BLACK = 2, // Green on Black.
		COLOUR_YELLOW_ON_BLACK = 3, // Yellow on Black.
		COLOUR_BLUE_ON_BLACK = 4, // Blue on Black.
		COLOUR_MAGENTA_ON_BLACK = 5, // Magenta on Black.
		COLOUR_CYAN_ON_BLACK = 6, // Cyan on Black.
		COLOUR_BLACK_ON_GRAY = 7, // Black on Gray.
		COLOUR_BLACK_ON_WHITE = 8, // Black on White.
		COLOUR_RED_ON_WHITE = 9, // Red on White.
		COLOUR_GREEN_ON_WHITE = 10, // Green on White.
		COLOUR_YELLOW_ON_WHITE = 11, // Yellow on White.
		COLOUR_BLUE_ON_WHITE = 12, // Blue on White.
		COLOUR_MAGENTA_ON_WHITE = 13,// Magenta on White.
		COLOUR_CYAN_ON_WHITE = 14, // Cyan on White.
		COLOUR_WHITE_ON_WHITE = 15 // White on White.
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

	static void SetRgb(Color color)
	{
		switch (color) 
		{ 
			case COLOUR_WHITE_ON_BLACK:    // White on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				break; 

			case COLOUR_RED_ON_BLACK:    // Red on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED); 
				break; 

			case COLOUR_GREEN_ON_BLACK:    // Green on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
				break;

			case COLOUR_YELLOW_ON_BLACK:    // Yellow on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN); 
				break; 

			case COLOUR_BLUE_ON_BLACK:    // Blue on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE); 
				break; 

			case COLOUR_MAGENTA_ON_BLACK:    // Magenta on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE); 
				break; 

			case COLOUR_CYAN_ON_BLACK:    // Cyan on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				break; 

			case COLOUR_BLACK_ON_GRAY:    // Black on Gray. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | BACKGROUND_INTENSITY); 
				break; 

			case COLOUR_BLACK_ON_WHITE:    // Black on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE); 
				break; 

			case COLOUR_RED_ON_WHITE:    // Red on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED); 
				break; 

			case COLOUR_GREEN_ON_WHITE:    // Green on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN); 
				break; 

			case COLOUR_YELLOW_ON_WHITE:    // Yellow on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
				break;

			case COLOUR_BLUE_ON_WHITE:    // Blue on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_BLUE); 
				break; 

			case COLOUR_MAGENTA_ON_WHITE:    // Magenta on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE); 
				break; 

			case COLOUR_CYAN_ON_WHITE:    // Cyan on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				break; 

			case COLOUR_WHITE_ON_WHITE:    // White on White. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED  | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				break; 

			default:    // White on Black. 
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); 
				break; 
		}
	}

	static void fontSize(int a, int b) { 
		PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx = new CONSOLE_FONT_INFOEX(); 
		lpConsoleCurrentFontEx->cbSize = sizeof(CONSOLE_FONT_INFOEX); 
		GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, lpConsoleCurrentFontEx); 
		lpConsoleCurrentFontEx->dwFontSize.X = a; 
		lpConsoleCurrentFontEx->dwFontSize.Y = b; 
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), 0, lpConsoleCurrentFontEx); 
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