#pragma once

class Player;
class ShootingGame
{
public:
	static void GameProgress();
private:
	static Player NewPlayer;
	static const int InterFrame = 150;

	static void Loading();
	static void GameUpdate();
	static void Collision();

	ShootingGame() {}
};