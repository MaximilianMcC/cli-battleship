#include "boat.hpp"
#include <vector>
#include <string>
#include "consoleUtils.hpp"

#pragma once

struct RenderSettings
{
	int CellWidth;
	// int CellHeight;

	std::string TopLeft;
	std::string TopRight;
	std::string BottomLeft;
	std::string BottomRight;

	std::string TopSeparator;
	std::string BottomSeparator;
	std::string TopBottom;

	std::string Side;
	std::string Content;
	std::string Separator;

	bool UseSeparator;
	std::string SeparatorSideLeft;
	std::string SeparatorSideRight;
	std::string SeparatorContent;
	std::string SeparatorJoiner;
};

// TF: Class
class Board
{
private:
	// TODO: Use definitions
	static const short width = 10;
	static const short height = 10;
	static const short maxBoats = 5;

	// The actual board
	std::vector<Vector2> misses = {};
	std::vector<Vector2> hits = {};
	// std::vector<Boat*> boats = {};

	bool BoatAtPosition(Vector2 cell);

	// Drawing stuff
	std::string generateBoardRow(std::string leftSide, std::string middle, int middleWidth, std::string separator, std::string rightSide, int rows);
	void drawGrid(Vector2 position, RenderSettings settings, std::string title = "");
	void drawToGrid(Vector2 boardPosition, RenderSettings boardRenderSettings, Vector2 cellCoordinate, std::string content, const char* color = ConsoleUtils::Color::White);
	void drawGlyphsAt(std::vector<Vector2> cells, std::string glyphs, const char* color,  Vector2 position, RenderSettings settings);

public:
	// Board() {}
	// ~Board() {}
	bool addBoat(Boat& boat);



	void attackSpot(Vector2 cell);

	// Draw the board
	// TF: Default Parameter
	void draw(Vector2 position, RenderSettings settings, std::string gridText = "");
	Vector2 measureGrid(RenderSettings settings);
};