#pragma once

#include <StaticLibrary/Object.h>

class Player : public Object
{
public:
	static bool IsGameUpdate;

	void Update() override;

	Player();
	~Player() {}

	Player(const Player& _ref) = delete;
	Player(Player&& _ref) noexcept = delete;
	Player& operator=(const Player& _ref) = delete;
	Player& operator=(Player&& _ref) noexcept = delete;
private:
	bool IsBomb(const Point& _pt) const;
	void IsItem(const Point& _pt) const;
};
