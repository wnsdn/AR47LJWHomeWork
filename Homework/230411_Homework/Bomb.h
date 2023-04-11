#pragma once

#include <StaticLib/ConsoleGameObject.h>

class Bomb : public ConsoleGameObject
{
public:
	void Init(int _BombPower);
	void Update() override;
	void Render() override;

	Bomb();
	~Bomb();

	Bomb(const Bomb& _ref) = delete;
	Bomb(Bomb&& _ref) noexcept = delete;
	Bomb& operator=(const Bomb& _ref) = delete;
	Bomb& operator=(Bomb&& _ref) noexcept = delete;
protected:

private:
	int BoomCount = 10;
	int MaxExpPower = 5;
	int CurExpPower = 0;
};

