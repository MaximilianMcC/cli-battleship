#include "boat.hpp"

#pragma once

class Board
{
private:
	// TODO: Use definitions
	static const short width = 10;
	static const short height = 10;
	static const short maxBoats = 5;

	// The stuff on the actual board
	short misses[height][width];
	Boat* boats[maxBoats];

	Boat* BoatAtPosition(Vector2 position);

public:
	// Board() {}
	// ~Board() {}

	// Returns true/false depending on if theres a valid position
	bool addBoat(Boat& boat);

	// Returns true/false depending on hit or miss
	bool attackSpot(Vector2 position);
};