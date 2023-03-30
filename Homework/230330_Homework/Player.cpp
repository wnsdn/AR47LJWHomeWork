#include "Player.h"

#include <Windows.h>
#include <conio.h>

#include "ConsoleGameScreen.h"
#include "Bullet.h"

Player::Player()
	: Pos(), BulletPtr(nullptr)
{
}

void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(ConsoleGameScreen::Instance().InterFrame);
		return;
	}

	char Ch = _getch();

	Point NextPos = { 0, 0 };

	switch (Ch)
	{
	case 'a':
	case 'A':
		NextPos = Pos;
		NextPos.x -= 1;
		if (false == ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			Pos.x -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.x += 1;
		if (false == ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			Pos.x += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.y -= 1;
		if (false == ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			Pos.y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.y += 1;
		if (false == ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			Pos.y += 1;
		}
		break;
	case 'f':
	case 'F':
		if (BulletPtr->CurrentBullet >= Bullet::ArrBulletCount)
		{
			break;
		}
		BulletPtr[BulletPtr->CurrentBullet].SetPos(Pos);
		BulletPtr[BulletPtr->CurrentBullet].FireOn();
		break;
	default:
		break;
	}

	Sleep(ConsoleGameScreen::Instance().InterFrame);
}

void Player::Render()
{
	ConsoleGameScreen::Instance().SetScreenCharacter(Pos, '*');
}