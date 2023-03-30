#pragma once
#include "ConsoleGameMath.h"

class Bullet
{
public:
	static const int ArrBulletCount = 10;
	static int CurrentBullet;

	static void AllRender();
	static void AllUpdate();
	void Update();
	void Render();

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	Point GetPos() const
	{
		return Pos;
	}
	
	void SetPos(const Point& _Value)
	{
		Pos = _Value;
	}

	bool IsFire() const
	{
		return Fire;
	}

	void FireOn()
	{
		Fire = true;
	}

private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Point Pos;
	bool Fire;

	Bullet();
};

