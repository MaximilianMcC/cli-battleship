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
		ConsoleUtils::GotoXY(0, 0);
	}

	// The large display settings shows your view of the opponents board
	RenderSettings largeBoard;
	{
		largeBoard.CellWidth = 4;

		largeBoard.TopLeft = "╔";
		largeBoard.TopRight = "╗";
		largeBoard.BottomLeft = "╚";
		largeBoard.BottomRight = "╝";

		largeBoard.TopSeparator = "╤";
		largeBoard.BottomSeparator = "╧";
		largeBoard.TopBottom = "═";

		largeBoard.Side = "║";
		largeBoard.Content = " ";
		largeBoard.Separator = "│";

		largeBoard.UseSeparator = true;
		largeBoard.SeparatorSideLeft = "╟";
		largeBoard.SeparatorSideRight = "╢";
		largeBoard.SeparatorContent = "─";
		largeBoard.SeparatorJoiner = "┼";
	};

	// The small display settings shows your own board
	RenderSettings smallBoard;
	{
		smallBoard.CellWidth = 2;

		smallBoard.TopLeft = "╔";
		smallBoard.TopRight = "╗";
		smallBoard.BottomLeft = "╚";
		smallBoard.BottomRight = "╝";

		smallBoard.TopBottom = "═";

		smallBoard.Side = "║";
		smallBoard.Content = " ";
		smallBoard.Separator = "";

		smallBoard.UseSeparator = false;
	};

	// Draw a little title thingy
	std::cout << "\n";
	ConsoleUtils::centreText("BATTLESHIPS");


	// Make a board for the player and for the AI
	Board* playerBoard = new Board();
	Board* opponentBoard = new Board();

	// Make the layout to have the opponents grid (from the players perspective)
	// to be large and on the left side, and to have the players board
	// to be smaller and in the bottom right. Both are centered on both axis
	// TODO: Add a fake radar visual that spins around in the top right
	Vector2 opponentGridSize = opponentBoard->measureGrid(largeBoard);
	Vector2 playerGridSize = playerBoard->measureGrid(smallBoard);
	
	// Get the max size of the two
	//! padding SHOULD just be 1. Somewhere 1 is being added
	const int padding = 2;
	Vector2 maxSize = Vector2(
		opponentGridSize.X + padding + playerGridSize.X,
		opponentGridSize.Y
	);

	// Get the origin to draw them centered
	Vector2 centeredOrigin = (ConsoleUtils::getConsoleSize() - maxSize) / 2;

	// Get the positions of both boards
	//? padding should just be 1. Somewhere 1 is being added
	Vector2 opponentPosition = centeredOrigin;
	Vector2 playerPosition = centeredOrigin + opponentGridSize.justX() + Vector2(padding, 0);

	// Draw both the boards
	// TODO: When you make a move then do a radar wipe animation thingy and reveal the points like that
	opponentBoard->draw(opponentPosition, largeBoard, "OPPONENTS FLEET");
	playerBoard->draw(playerPosition, smallBoard, "YOUR FLEET");



	// Hit, miss, target
	// TODO: Colorblind mode that makes the red magenta
	// playerBoard->DrawToGrid(playerBoardPosition, {6, 3}, " >< ", ConsoleUtils::Color::Red);
	// playerBoard->DrawToGrid({0, 0}, largeBoard, {6, 3}, " >< ", ConsoleUtils::Color::Magenta);
	// playerBoard->DrawToGrid({0, 0}, largeBoard, {4, 7}, " () ", ConsoleUtils::Color::Cyan);
	// playerBoard->DrawToGrid({0, 0}, largeBoard, {2, 5}, " ┤├ ", ConsoleUtils::Color::Green);

	// playerBoard->DrawToGrid(position, largeBoard, {0, 0}, " ><", ConsoleUtils::Color::Magenta);
	// playerBoard->DrawToGrid(position, largeBoard, {9, 9}, " ><", ConsoleUtils::Color::Magenta);
	// playerBoard->DrawToGrid(position, largeBoard, {4, 7}, " ()", ConsoleUtils::Color::Cyan);
	// playerBoard->DrawToGrid(position, largeBoard, {2, 5}, " ┤├", ConsoleUtils::Color::Green);

	// Get rid of the boards when we're done
	delete playerBoard;
	delete opponentBoard;

	// Stop the console from closing
	std::getchar();
	ConsoleUtils::ClearScreen();
	ConsoleUtils::showCursor();
}