#include "board.hpp"
#include "consoleUtils.hpp"
#include <string>

void Board::draw(Vector2 position, RenderSettings settings, std::string gridText)
{
	// Draw the grid
	drawGrid(position, settings, gridText);

	// Draw everything on the grid
	drawGlyphsAt(misses, "()", ConsoleUtils::Color::BrightBlue, position, settings);
	drawGlyphsAt(hits, "><", ConsoleUtils::Color::BrightRed, position, settings);
}



void Board::drawGrid(Vector2 position, RenderSettings settings, std::string title)
{
	// Draw the top section
	ConsoleUtils::GotoXY(position.X, position.Y++);
	std::cout << generateBoardRow(settings.TopLeft, settings.TopBottom, settings.CellWidth, settings.TopSeparator, settings.TopRight, width) << "\n";

	// If supplied, draw a title
	if (title != "")
	{
		ConsoleUtils::GotoXY(position.X + 2, position.Y - 1);
		std::cout << " " << title << " ";
	};

	// Draw the middle sections
	// TF: Constant
	const std::string middleRow = generateBoardRow(settings.Side, settings.Content, settings.CellWidth, settings.Separator, settings.Side, width);
	const std::string middleRowSeparator = generateBoardRow(settings.SeparatorSideLeft, settings.SeparatorContent, settings.CellWidth, settings.SeparatorJoiner, settings.SeparatorSideRight, width);
	for (int i = 0; i < height; i++)
	{
		// Draw an actual "cell"
		ConsoleUtils::GotoXY(position.X, position.Y++);
		std::cout << middleRow << "\n";

		// Add the separator under the
		// content (if we asked for it)
		if (settings.UseSeparator)
		{
			// There is no separator on the very bottom
			if (i == (height - 1)) continue;

			// Draw the separator
			ConsoleUtils::GotoXY(position.X, position.Y++);
			std::cout << middleRowSeparator << "\n";
		}
	}

	// Draw the bottom section
	ConsoleUtils::GotoXY(position.X, position.Y++);
	std::cout << generateBoardRow(settings.BottomLeft, settings.TopBottom, settings.CellWidth, settings.BottomSeparator, settings.BottomRight, width) << "\n";
}



void Board::drawToGrid(Vector2 boardPosition, RenderSettings settings, Vector2 cellCoordinate, std::string content, const char* color)
{
	// Set the color to draw with
	std::cout << color;
	
	// Turn both relative coordinates to screen coordinates
	// TODO: Don't do the != "" thing (really dodgy)
	boardPosition += Vector2(1) + (cellCoordinate * Vector2((settings.SeparatorContent != "") + settings.CellWidth, 1 + settings.UseSeparator));
	ConsoleUtils::GotoXY(boardPosition);

	// Draw the grid
	std::cout << content;

	// Reset the color
	std::cout << ConsoleUtils::Color::Reset;
}


// TODO: see if u can find a vscode extrnsion 2 audio update h files
void Board::drawGlyphsAt(std::vector<Vector2> cells, std::string glyph, const char* color, Vector2 position, RenderSettings settings)
{
	// Check for if we need to add padding
	// TODO: Add more than just 1 space depending on cell size
	if (settings.CellWidth > 2) glyph = (" " + glyph);

	// Loop over every cell
	for (int i = 0; i < cells.size(); i++)
	{
		// Draw the glyph at the cells position
		drawToGrid(position, settings, cells[i], glyph, color);
	}
}



Vector2 Board::measureGrid(RenderSettings settings)
{
	// TODO: Add a cell height thing
	// Add the width of the cells, and also include the separators if they were used
	int totalWidth = ((width * settings.CellWidth) + (width * settings.UseSeparator)) + !settings.UseSeparator;
	int totalHeight = ((height * 1) + (height * settings.UseSeparator)) + !settings.UseSeparator;

	return Vector2(totalWidth, totalHeight);
}



std::string Board::generateBoardRow(std::string leftSide, std::string middle, int middleWidth, std::string separator, std::string rightSide, int rows)
{
	// TODO: Use char arrays because its quicker maybe
	std::string row;

	// Add the left side
	row += leftSide;

	// Generate the middle
	std::string middleContent = "";
	for (int i = 0; i < middleWidth; i++)
	{
		middleContent += middle;
	}

	// Add the middle sections
	for (int i = 0; i < (rows - 1); i++)
	{
		row += middleContent;
		row += separator;
	}
	row += middleContent;

	// Add the right side
	row += rightSide;
	
	// Return the generated row
	return row;
}