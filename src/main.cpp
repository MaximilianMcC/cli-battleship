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
	Board::RenderSettings largeBoard;
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
	Board::RenderSettings smallBoard;
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

	// Make a board for the player and for the AI
	Board* playerBoard = new Board();
	Board* opponentBoard = new Board();

	playerBoard->attackSpot({0, 0});
	playerBoard->attackSpot({2, 7});
	playerBoard->attackSpot({4, 3});
	playerBoard->attackSpot({7, 8});

	// Centre the player grid (debug
	Vector2 gridSize = playerBoard->MeasureGrid(largeBoard);
	Vector2 position = Vector2(
		(ConsoleUtils::getConsoleWidth() - gridSize.X) / 2,
		(ConsoleUtils::getConsoleHeight() - gridSize.Y) / 2
	);

	// Draw the grid in the centre
	playerBoard->Draw(position, largeBoard);


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
}


/*
Carrier (5)
 ╔╗
 ║║
 ║╢
 ║@
 ╚╝

Battleship (4)
 /\
 ││
 ╫╫
 ╰╯	

Cruiser (3)
 ╭╮
 ├┤
 └┘

Submarine (3)
 ╭╮
 ├│
 └┘

Destroyer (2)
 /\
 ╚╝
*/