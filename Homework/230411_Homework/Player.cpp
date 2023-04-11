#include "Player.h"

#include <conio.h>

#include <StaticLib/ConsoleGameScreen.h>
#include "ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Bomb.h"

bool Player::IsGameUpdate = true;

void Player::Update()
{
	if (0 == _kbhit())
	{
		return;
	}

	char Ch = _getch();
	int2 NextPos = GetPos();

	switch (Ch)
	{
	case 'w':
	case 'W':
	{
		NextPos.y -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos)
			&& false == IsBomb(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPos.y += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos)
			&& false == IsBomb(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 'a':
	case 'A':
	{
		NextPos.x -= 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos)
			&& false == IsBomb(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPos.x += 1;
		if (false == ConsoleGameScreen::GetMainScreen().IsScreenOver(NextPos)
			&& false == IsBomb(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init(BombPower);
		NewBomb->SetPos(GetPos());

		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	}
}

bool Player::IsBomb(const int2& _NextPos) const
{
	GameEngineArray<ConsoleGameObject*>& BombGroup
		= ConsoleObjectManager::GetGroup(ObjectOrder::Bomb);

	int Size = BombGroup.Size();
	for (int i = 0; i < Size; ++i)
	{
		int2 BombPos = BombGroup[i]->GetPos();
		if (BombGroup[i]->GetUpdate() && _NextPos == BombPos)
		{
			return true;
		}
	}

	return false;
}

Player::Player()
{
	SetPos(ConsoleGameScreen::GetMainScreen().GetScreenSize().Half());
	SetRenderChar('*');
}

Player::~Player()
{
}
