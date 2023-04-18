#include "Player.h"

#include <conio.h>
#include <list>

#include <StaticLibrary/ConsoleGameScreen.h>
#include <StaticLibrary/ObjectManager.h>

#include "Bomb.h"
#include "Item.h"
#include "Enum.h"

using std::list;

bool Player::IsGameUpdate = true;

void Player::Update()
{
	Object::Update();

	if (!_kbhit())
	{
		return;
	}

	char Ch = _getch();
	Pt NextPt = GetPoint();

	switch (Ch)
	{
	case 'w':
	case 'W':
	{
		NextPt.y -= 1;
		if (!ConsoleGameScreen::GetMainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			SetPoint(NextPt);
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPt.y += 1;
		if (!ConsoleGameScreen::GetMainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			SetPoint(NextPt);
		}
		break;
	}
	case 'a':
	case 'A':
	{
		NextPt.x -= 1;
		if (!ConsoleGameScreen::GetMainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			SetPoint(NextPt);
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPt.x += 1;
		if (!ConsoleGameScreen::GetMainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			SetPoint(NextPt);
		}
		break;
	}
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ObjectManager::InsertObject<Bomb>(ObjectGroup::Bomb);
		NewBomb->SetPoint(GetPoint());
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}

	IsItem(GetPoint());
}

Player::Player()
{
	Pt ScreenSize = ConsoleGameScreen::GetMainScreen().GetSize();

	SetPoint({ ScreenSize.x / 2, ScreenSize.y - 1 });
	SetRenderChar('*');
}

bool Player::IsBomb(const Point& _pt) const
{
	list<Object*>& Group = ObjectManager::GetObjectGroup(ObjectGroup::Bomb);

	for (auto obj : Group)
	{
		if (obj->GetPoint() == _pt)
		{
			return true;
		}
	}

	return false;
}

void Player::IsItem(const Point& _pt) const
{
	list<Object*>& Group = ObjectManager::GetObjectGroup(ObjectGroup::Item);

	for (auto obj : Group)
	{
		if (obj->GetPoint() == _pt)
		{
			obj->SetActive(false);
			Bomb::SetPower(Bomb::GetPower() + 1);
		}
	}
}