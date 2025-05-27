#include <iostream>
#include "consoleUtils.hpp"
#include "board.hpp"
#include <windows.h>

int main()
{
	{
		// Chuck us on UTF8 so we can use boxdrawing characters
		// otherwise we'll just using ascii (kinda limiting)
		SetConsoleOutputCP(CP_UTF8);

		// Enable ansii codes for colors
		HANDLE output = GetStdHandle(STD_ERROR_HANDLE);
		DWORD mode = 0;
		GetConsoleMode(output, &mode);
		SetConsoleMode(output, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	
		// Clear anything (for if we're launching via cli)
		ConsoleUtils::ClearScreen();
		ConsoleUtils::hideCursor();
	}

	// Make a board for the player and for the AI
	Board* playerBoard = new Board();
	Board* opponentBoard = new Board();

	Vector2 playerBoardPosition = {40, 5};
	playerBoard->DrawGrid(playerBoardPosition);
	playerBoard->DrawToGrid(playerBoardPosition, {0, 0}, " A1", ConsoleUtils::Color::BrightBlack);
	playerBoard->DrawToGrid(playerBoardPosition, {1, 0}, " A2", ConsoleUtils::Color::BrightBlack);
	playerBoard->DrawToGrid(playerBoardPosition, {0, 1}, " B1", ConsoleUtils::Color::BrightBlack);
	playerBoard->DrawToGrid(playerBoardPosition, {1, 1}, " B2", ConsoleUtils::Color::BrightBlack);

	// Hit, miss, target
	// TODO: Colorblind mode that makes the red magenta
	playerBoard->DrawToGrid(playerBoardPosition, {6, 3}, " >< ", ConsoleUtils::Color::Red);
	playerBoard->DrawToGrid(playerBoardPosition, {6, 3}, " >< ", ConsoleUtils::Color::Magenta);
	playerBoard->DrawToGrid(playerBoardPosition, {4, 7}, " () ", ConsoleUtils::Color::Cyan);
	playerBoard->DrawToGrid(playerBoardPosition, {2, 5}, " ┤├ ", ConsoleUtils::Color::Green);

	

	// Get rid of the boards when we're done
	delete playerBoard;
	delete opponentBoard;

	// Stop the console from closing
	std::getchar();
}