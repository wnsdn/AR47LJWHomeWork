#pragma once
#include "ConsoleGameMath.h"

class Player
{
public:
	Player();

	void SetPos(const Point& _Value)
	{
		Pos = _Value;
	}

	Point GetPos() const
	{
		return Pos;
	}

	bool GetFire() const
	{
		return IsFire;
	}

	void Input();

private:
	static const int InterFrame = 200;
	Point Pos = Point(0, 0);
	bool IsFire = false;
};

