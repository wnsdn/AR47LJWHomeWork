#include <iostream>
#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

int main()
{
	Player NewPlayer = Player();
	Point ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	NewPlayer.SetPos(Point(ScreenSize.Half().x, ScreenSize.y - 1));

	while (true)
	{
		system("cls");

		ConsoleGameScreen::GetMainScreen().ScreenClear();

		ConsoleGameScreen::GetMainScreen().SetScreenCharacter(NewPlayer.GetPos(), '*');
		if (NewPlayer.GetFire())
		{
			ConsoleGameScreen::GetMainScreen().SetScreenBullet(Bullet::GetBullet().GetPos(), 'O');
			Bullet::GetBullet().Move();
		}

		ConsoleGameScreen::GetMainScreen().ScreenPrint();

		NewPlayer.Input();
	}
}