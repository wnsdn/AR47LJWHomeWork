#pragma once
#include "ConsoleGameObject.h"

class Bullet : public ConsoleGameObject
{
public:
	static const int ArrBulletCount = 10;

	static Bullet* GetArrBullet()
	{
		return ArrBullet;
	}

	void AllUpdate();
	void AllRender();
private:
	static Bullet ArrBullet[Bullet::ArrBulletCount];

	Bullet();
};