#include "Player.h"

#include <conio.h>

#include "ConsoleGameScreen.h"
#include "Bullet.h"

void Player::Update()
{
	Input();
}

void Player::Input()
{
	if (!_kbhit())
	{
		return;
	}

	char ch = _getch();
	Point NextPos = Pos;
	switch (ch)
	{
	case 'a':
	case 'A':
	{
		NextPos.x -= 1;
		if (ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			break;
		}
		Pos.x -= 1;
		break;
	}
	case 'd':
	case 'D':
	{
		NextPos.x += 1;
		if (ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			break;
		}
		Pos.x += 1;
		break;
	}
	case 'w':
	case 'W':
	{
		NextPos.y -= 1;
		if (ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			break;
		}
		Pos.y -= 1;
		break;
	}
	case 's':
	case 'S':
	{
		NextPos.y += 1;
		if (ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			break;
		}
		Pos.y += 1;
		break;
	}
	case 'f':
	case 'F':
	{
		ShotUpdate();
		break;
	}
	default:
		break;
	}
}

void Player::ShotUpdate()
{
	Bullet& NewBullet = BulletPtr[BulletCount];
	NewBullet.SetPos(Pos);
	NewBullet.SetUpdateValue(true);

	++BulletCount;
	if (BulletCount >= Bullet::ArrBulletCount)
	{
		BulletCount = 0;
	}
}

Player::Player()
{
	Pos = { ConsoleGameScreen::ScreenX / 2, ConsoleGameScreen::ScreenY - 1 };
	RenderChar = '*';

	BulletPtr = Bullet::GetArrBullet();
	BulletCount = 0;
}
