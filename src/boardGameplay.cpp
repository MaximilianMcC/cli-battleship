#include "board.hpp"

bool Board::BoatAtPosition(Vector2 position)
{
	

	// There was no collision (miss)
	return false;
}

void Board::attackSpot(Vector2 cell)
{
	// Check for if we hit a boat
	bool hitBoat = BoatAtPosition(cell);
	if (hitBoat == false)
	{
		// We did not hit a boat. Add a miss to the board
		misses.push_back(cell);
	}
}