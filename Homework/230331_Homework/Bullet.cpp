#include "Bullet.h"

#include "ConsoleGameScreen.h"

Bullet Bullet::ArrBullet[Bullet::ArrBulletCount];

void Bullet::AllUpdate()
{
	for (int i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (!ArrBullet[i].GetUpdateValue())
		{
			continue;
		}

		if (ConsoleGameScreen::Instance().IsScreenOver(ArrBullet[i].Pos))
		{
			ArrBullet[i].SetUpdateValue(false);
		}

		--ArrBullet[i].Pos.y;
	}
}

void Bullet::AllRender()
{
	for (int i = 0; i < Bullet::ArrBulletCount; i++)
	{
		if (!ArrBullet[i].GetUpdateValue())
		{
			continue;
		}

		ArrBullet[i].Render();
	}
}

Bullet::Bullet()
{
	RenderChar = '^';
	SetUpdateValue(false);
}
