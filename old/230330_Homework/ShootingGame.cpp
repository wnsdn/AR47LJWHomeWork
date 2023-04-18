#include "ShootingGame.h"

#include <iostream>

#include "Player.h"
#include "Bullet.h"
#include "ConsoleGameScreen.h"

void ShootingGame::GameProgress()
{
	Player NewPlayer;
	NewPlayer.SetBulletArr(Bullet::GetArrBullet());
	NewPlayer.SetPos(Point(ConsoleGameScreen::Instance().GetScreenSize().Half().x, ConsoleGameScreen::Instance().GetScreenSize().y - 1));

	while (true)
	{
		system("cls");

		ConsoleGameScreen::Instance().ScreenClear();

		NewPlayer.Render();
		Bullet::AllRender();

		ConsoleGameScreen::Instance().ScreenPrint();

		NewPlayer.Input();
		Bullet::AllUpdate();
	}
}

ShootingGame::ShootingGame()
{
}
