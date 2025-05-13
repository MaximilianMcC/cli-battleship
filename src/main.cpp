#include <iostream>
#include "consoleUtils.hpp"
#include "board.hpp"

int main()
{
	// Clear anything (for if we're launching via cli)
	ConsoleUtils::ClearScreen();

	// Make a board for the player and for the AI
	Board* playerBoard = new Board();
	Board* opponentBoard = new Board();


	
	// Get rid of the boards when we're done
	delete playerBoard;
	delete opponentBoard;

	// Stop the console from closing
	std::getchar();
}