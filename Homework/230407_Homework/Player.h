#pragma once

#include <GameEngineLib/GameEngineObject.h>

class Player : public GameEngineObject
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

};

