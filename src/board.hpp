#include "boat.hpp"
#include <vector>
#include <string>
#include "consoleUtils.hpp"

#pragma once

class Board
{
private:
	// TODO: Use definitions
	static const short width = 10;
	static const short height = 10;
	static const short maxBoats = 5;

	// The actual board
	std::vector<Vector2> misses = {};
	std::vector<Boat*> boats = {};

	Boat* BoatAtPosition(Vector2 position);

	std::string generateBoardRow(std::string leftSide, std::string middle, std::string separator, std::string rightSide, int rows);

public:
	// Board() {}
	// ~Board() {}

	// Returns true/false depending on if theres a valid position
	bool addBoat(Boat& boat);

	// Returns true/false depending on hit or miss
	bool attackSpot(Vector2 position);

	// Draw the board nicely
	// TF: Default Parameter
	void DrawGrid(Vector2 position);
	void DrawToGrid(Vector2 boardPosition, Vector2 cellCoordinate, std::string content, const char* color = ConsoleUtils::Color::White);
};