#pragma once

#include <StaticLib/ConsoleGameObject.h>

class Player : public ConsoleGameObject
{
public:
	static bool IsGameUpdate;

	void Update() override;

	Player();
	~Player();

	Player(const Player& _ref) = delete;
	Player(Player&& _ref) noexcept = delete;
	Player& operator=(const Player& _ref) = delete;
	Player& operator=(Player&& _ref) noexcept = delete;
protected:

private:
	int BombPower = 5;
};