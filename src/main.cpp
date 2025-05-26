#include <iostream>
#include "consoleUtils.hpp"
#include "board.hpp"

int main()
{
	{
		// Chuck us on UTF8 so we can use boxdrawing characters
		// otherwise we'll just pring ascii (kinda limiting)
		SetConsoleOutputCP(CP_UTF8);
	
		// Clear anything (for if we're launching via cli)
		ConsoleUtils::ClearScreen();
	}

	// Make a board for the player and for the AI
	Board* playerBoard = new Board();
	Board* opponentBoard = new Board();

	playerBoard->DrawGrid((Vector2){0, 0});
	
	// Get rid of the boards when we're done
	delete playerBoard;
	delete opponentBoard;

	// Stop the console from closing
	std::getchar();
}