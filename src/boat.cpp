#include "boat.hpp"

Boat::Boat(char asciiSegments[], short size, const Vector2 position, bool vertical)
{
	// Set the size of the boat, and wether
	// its positioned horizontally or vertically
	Size = size;
	Vertical = vertical;

	// Copy the ascii array thingy into the class
	ascii = new char[Size];
	for (short i = 0; i < Size; i++) ascii[i] = asciiSegments[i];

	// Set the position of the boat
	Position = position;
}

bool Boat::atPosition(Vector2 hitPosition)
{
	// Check for if there is a section of
	// our boat at the requested position
	for (short i = 0; i < Size; i++)
	{
		// Check for if the current segment was hit
		if (hitPosition == Position) return true;

		// There was no hit. Move onto the next section
		Vertical ? Position.Y++ : Position.X++;
	}

	// There were no hits at all (miss)
	return false;
}

Boat::~Boat()
{
	// Get rid of the ascii segments array
	delete[] ascii;
}