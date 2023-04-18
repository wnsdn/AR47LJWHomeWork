#include "Bullet.h"

#include <Windows.h>
#include <conio.h>

#include "ConsoleGameScreen.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];
int Bullet::CurrentBullet = 0;

Bullet::Bullet()
	: Pos()
	, Fire(false)
{
}

void Bullet::AllRender() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}

		ArrBullet[i].Render();
	}
}

void Bullet::AllUpdate() 
{
	for (size_t i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (false == ArrBullet[i].IsFire())
		{
			continue;
		}
		else
		{
			Bullet::CurrentBullet = (int)i + 1;
		}

		ArrBullet[i].Update();
	}
}

void Bullet::Render()
{
	if (true == Fire)
	{
		ConsoleGameScreen::Instance().SetScreenCharacter(Pos, '^');
		
	}
}

void Bullet::Update() 
{
	if (true == Fire)
	{
		--Pos.y;
	}
}