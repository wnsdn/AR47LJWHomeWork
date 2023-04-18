#pragma once
#include "ConsoleGameObject.h"

class Bullet;
class Player : public ConsoleGameObject
{
public:
	void Update();

	Player();
private:
	Bullet* BulletPtr;
	int BulletCount;

	void Input();
	void ShotUpdate();
};

