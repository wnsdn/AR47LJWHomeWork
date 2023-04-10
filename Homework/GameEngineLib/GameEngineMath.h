#pragma once

class int2
{
public:
	int x;
	int y;

	int2 Half()
	{
		return { x / 2, y / 2 };
	}

	int2 operator*(int _value)
	{
		return { x * _value, y * _value };
	}
	int2 operator+(const int2& _ref)
	{
		return { x + _ref.x, y + _ref.y };
	}

	int2()
		: x(0), y(0)
	{}
	
	int2(const int _x, const int _y)
		: x(_x), y(_y)
	{}

	int2(const int2& _ref)
		: x(_ref.x), y(_ref.y)
	{}
};