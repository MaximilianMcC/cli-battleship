#include "board.hpp"

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