#pragma once

class Point
{
public:
	int x;
	int y;

	Point Half()
	{
		return { x / 2, y / 2 };
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