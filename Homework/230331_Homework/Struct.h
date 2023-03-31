#pragma once

struct Point
{
	int x;
	int y;

	bool operator==(const Point& ref)
	{
		return x == ref.x && y == ref.y;
	}

	Point()
		: x(0), y(0)
	{
	}

	Point(int _x, int _y)
		: x(_x), y(_y)
	{
	}
};
