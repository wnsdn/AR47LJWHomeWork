#pragma once

struct Point
{
	static const Point Dir[4];

	int x;
	int y;

	bool operator==(const Point& _pt) const
	{
		return x == _pt.x && y == _pt.y;
	}
	const Point operator+(const Point& _pt) const
	{
		return { x + _pt.x, y + _pt.y };
	}
	const Point operator+(const int _i) const
	{
		return { x + _i, y + _i };
	}
	const Point operator-(const Point& _pt) const
	{
		return { x - _pt.x, y - _pt.y };
	}
	const Point operator-(const int _i) const
	{
		return { x - _i, y - _i };
	}
	const Point operator*(const int _i) const
	{
		return { x * _i, y * _i };
	}

	Point()
		: x(0), y(0)
	{}
	Point(const int _x, const int _y)
		: x(_x), y(_y)
	{}
	Point(const Point& _pt)
		: x(_pt.x), y(_pt.y)
	{}
};

