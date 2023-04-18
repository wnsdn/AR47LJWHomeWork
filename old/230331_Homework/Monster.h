#pragma once
#include "ConsoleGameObject.h"

class Monster : public ConsoleGameObject
{
public:
	static const int ArrMonsterCount = 14;

	static Monster* GetArrMonster()
	{
		return ArrMonster;
	}

	void AllUpdate();
	void AllRender();

	Monster();
private:
	static Monster ArrMonster[Monster::ArrMonsterCount];

	static int Dir;
	static int Tick;
};

