#include "Player.h"

#include <conio.h>

#include <GameEngineLib/GameEngineScreen.h>
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
		if (false == GameEngineScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPos.y += 1;
		if (false == GameEngineScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 'a':
	case 'A':
	{
		NextPos.x -= 1;
		if (false == GameEngineScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPos.x += 1;
		if (false == GameEngineScreen::GetMainScreen().IsScreenOver(NextPos))
		{
			SetPos(NextPos);
		}
		break;
	}
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ConsoleObjectManager::CreateConsoleObject<Bomb>(ObjectOrder::Bomb);
		NewBomb->Init();
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

Player::Player()
{
	SetPos(GameEngineScreen::GetMainScreen().GetScreenSize().Half());
	SetRenderChar('*');
}

Player::~Player()
{
}
