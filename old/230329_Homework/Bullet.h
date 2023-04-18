#pragma once
#include "ConsoleGameMath.h"

class Bullet
{
public:
	static Bullet& GetBullet()
	{
		static Bullet bullet;
		return bullet;
	}

	void SetPos(const Point& _Pos)
	{
		Pos = _Pos;
	}

	Point GetPos() const
	{
		return Pos;
	}

	void SetMove(const bool _move)
	{
		IsMove = _move;
	}

	void Move();
private:
	Point Pos = Point(0, 0);
	bool IsMove = false;

	Bullet();
};

