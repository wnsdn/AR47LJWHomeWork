#include "ShootingGame.h"

#include <iostream>
#include <Windows.h>

#include "ConsoleGameScreen.h"
#include "Player.h"
#include "Bullet.h"
#include "Monster.h"

Player ShootingGame::NewPlayer;

void ShootingGame::Loading()
{
	//==== Init ====
	for (int i = 0; i < Monster::ArrMonsterCount; i++)
	{
		Monster::GetArrMonster()[i].SetPos({ i + 3, 0 });
	}
}

void ShootingGame::GameUpdate()
{
	while (true)
	{
		//==== Update ====
		NewPlayer.Update();
		Bullet::GetArrBullet()->AllUpdate();
		Monster::GetArrMonster()->AllUpdate();

		Collision();

		//==== Render ====
		system("cls");
		ConsoleGameScreen::Instance().ScreenClear();

		NewPlayer.Render();
		Bullet::GetArrBullet()->AllRender();
		Monster::GetArrMonster()->AllRender();

		ConsoleGameScreen::Instance().ScreenPrint();
		Sleep(ShootingGame::InterFrame);
	}
}

void ShootingGame::Collision()
{
	Bullet* BulletArr = Bullet::GetArrBullet();
	Monster* MonsterArr = Monster::GetArrMonster();

	for (int i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (!BulletArr[i].GetUpdateValue())
		{
			continue;
		}

		for (int j = 0; j < Monster::ArrMonsterCount; j++)
		{
			if (!MonsterArr[j].GetUpdateValue())
			{
				continue;
			}

			if (BulletArr[i].GetPos() == MonsterArr[j].GetPos())
			{
				BulletArr[i].SetUpdateValue(false);
				MonsterArr[j].SetUpdateValue(false);
			}
		}
	}
}

void ShootingGame::GameProgress()
{
	Loading();
	GameUpdate();
}
