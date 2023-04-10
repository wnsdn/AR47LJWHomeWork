#pragma once

#include <GameEngineLib/GameEngineObject.h>

class Bomb : public GameEngineObject
{
public:
	void Init();
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
	int Length = 3;
	int2 index[4] = { {1,0},{0,1},{-1,0},{0,-1} };
};

