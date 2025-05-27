#pragma once

class Vector2
{
private:
public:
	short X;
	short Y;

	Vector2() { X = 0; Y = 0; }
	Vector2(short x, short y) { X = x; Y = y; }
	Vector2(short value) { X = value; Y = value; }

	Vector2 operator+(const Vector2& other) const { return Vector2(X + other.X, Y + other.Y); }
	Vector2& operator+=(const Vector2& other)
	{
		X += other.X;
		Y += other.Y;
		return *this;
	}

	Vector2 operator-(const Vector2& other) const { return Vector2(X - other.X, Y - other.Y); }
	Vector2 operator*(const Vector2& other) const { return Vector2(X * other.X, Y * other.Y); }
	Vector2 operator/(const Vector2& other) const { return Vector2(X / other.X, Y / other.Y); }

	Vector2 operator*(short scalar) const { return Vector2(X * scalar, Y * scalar); }

	bool operator==(const Vector2& other) const { return ((X == other.X) && (Y == other.Y)); }
};