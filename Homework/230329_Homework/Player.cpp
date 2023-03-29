#include "Player.h"
#include "ConsoleGameScreen.h"
#include "Bullet.h"

#include <conio.h>
#include <Windows.h>

Player::Player()
{
}

void Player::Input()
{
	if (0 == _kbhit())
	{
		Sleep(InterFrame);
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
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.x -= 1;
		}
		break;
	case 'd':
	case 'D':
		NextPos = Pos;
		NextPos.x += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.x += 1;
		}
		break;
	case 'w':
	case 'W':
		NextPos = Pos;
		NextPos.y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.y -= 1;
		}
		break;
	case 's':
	case 'S':
		NextPos = Pos;
		NextPos.y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			Pos.y += 1;
		}
		break;
	case 'f':
	case 'F':
		if (IsFire == false)
		{
			Bullet::GetBullet().SetPos(Point(Pos.x, Pos.y - 1));
			Bullet::GetBullet().SetMove(true);
			IsFire = true;
		}
		break;
	default:
		break;
	}

	Sleep(InterFrame);
}
