#include "vector2.hpp"

#pragma once

class Boat
{
private:
	char* ascii;

public:
	Vector2 Position;
	bool Vertical = true;
	short Size;

	Boat(char asciiSegments[], short size, Vector2 position, bool vertical);
	~Boat();

	bool atPosition(const Vector2 hitPosition);
};