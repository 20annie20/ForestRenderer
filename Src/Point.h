#pragma once

enum ColorType
{
	Brown,
	Orange,
	Yellow,
	Grey,
	Green,
	DarkGreen,
	Purple
};

struct Point {
	float x, y, z;
	
	Point() = default;
	Point(float x, float y, float z) : x(x), y(y), z(z) {};

	Point operator+ (const Point& first) const;
	Point operator- (const Point& first) const;
	
};

struct ColoredPoint : Point {
	ColorType color;

	ColoredPoint() = default;
	ColoredPoint(float x, float y, float z);
	ColoredPoint(float x, float y, float z, ColorType color);
};