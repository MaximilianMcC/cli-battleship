#include "board.hpp"
#include "consoleUtils.hpp"
#include <string>

Boat* Board::BoatAtPosition(Vector2 position)
{
	// Loop through all boats on
	// the board and check for if
	// one is at the position
	for (short i = 0; i < maxBoats; i++)
	{
		// Check for a hit
		if (boats[i]->atPosition(position)) return boats[i];
	}

	// There was no collision (miss)
	return nullptr;
}

bool Board::attackSpot(Vector2 position)
{
	// Check for if we hit a boat
	Boat* hitBoat = BoatAtPosition(position);
	if (hitBoat == nullptr) return false;
}

// TODO: Return the size of the board (just return position (we are updating it))
void Board::DrawGrid(Vector2 position)
{
	// Draw the top section
	ConsoleUtils::GotoXY(position.X, position.Y++);
	std::cout << generateBoardRow("╔", "═══", "╦", "╗", width) << "\n";

	// Draw the middle sections
	// TF: Constant
	const std::string middleRowTop = generateBoardRow("║", "   ", "║", "║", width);
	const std::string middleRowBottom = generateBoardRow("╠", "═══", "╬", "╣", width);
	for (int i = 0; i < (height - 1); i++)
	{
		ConsoleUtils::GotoXY(position.X, position.Y++);
		std::cout << middleRowTop << "\n";

		ConsoleUtils::GotoXY(position.X, position.Y++);
		std::cout << middleRowBottom << "\n";
	}
	ConsoleUtils::GotoXY(position.X, position.Y++);
	std::cout << middleRowTop << "\n";

	// Draw the bottom section
	ConsoleUtils::GotoXY(position.X, position.Y++);
	std::cout << generateBoardRow("╚", "═══", "╩", "╝", width) << "\n";
}

std::string Board::generateBoardRow(std::string leftSide, std::string middle, std::string separator, std::string rightSide, int rows)
{
	// TODO: Use char arrays because its quicker maybe
	std::string row;

	// Add the left side
	row += leftSide;

	// Add the middle sections
	for (int i = 0; i < (rows - 1); i++)
	{
		row += middle;
		row += separator;
	}
	row += middle;

	// Add the right side
	row += rightSide;
	
	// Return the generated row
	return row;
}

void Board::DrawToGrid(Vector2 boardPosition, Vector2 cellCoordinate, std::string content, const char* color)
{
	// Set the color to draw with
	std::cout << color;
	
	// Turn both relative coordinates to screen coordinates
	boardPosition += Vector2(2, 1) + (cellCoordinate * Vector2(4, 2));
	ConsoleUtils::GotoXY(boardPosition);

	// Draw the grid
	std::cout << content;

	// Reset the color
	std::cout << ConsoleUtils::Color::Reset;
}