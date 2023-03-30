#pragma once
#include "ConsoleGameMath.h"

class Player
{
public:
	void Input();
	void Render();

	Point GetPos() const
	{
		return Pos;
	}

	void SetPos(const Point& _Value)
	{
		Pos = _Value;
	}

	void SetBulletArr(class Bullet* _BulletPtr)
	{
		BulletPtr = _BulletPtr;
	}

	Player();

private:
	Point Pos;
	Bullet* BulletPtr;
};

