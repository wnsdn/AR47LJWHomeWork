#include "Player.h"

#include <conio.h>
#include <list>

#include <StaticLib/ConsoleGameScreen.h>
#include <StaticLib/ObjectManager.h>

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
	Point NextPt = Get_Pt();

	switch (Ch)
	{
	case 'w':
	case 'W':
	{
		NextPt.y -= 1;
		if (!ConsoleGameScreen::Get_MainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			Set_Pt(NextPt);
		}
		break;
	}
	case 's':
	case 'S':
	{
		NextPt.y += 1;
		if (!ConsoleGameScreen::Get_MainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			Set_Pt(NextPt);
		}
		break;
	}
	case 'a':
	case 'A':
	{
		NextPt.x -= 1;
		if (!ConsoleGameScreen::Get_MainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			Set_Pt(NextPt);
		}
		break;
	}
	case 'd':
	case 'D':
	{
		NextPt.x += 1;
		if (!ConsoleGameScreen::Get_MainScreen().IsOutOfScreen(NextPt)
			&& !IsBomb(NextPt))
		{
			Set_Pt(NextPt);
		}
		break;
	}
	case 'f':
	case 'F':
	{
		Bomb* NewBomb = ObjectManager::InsertObject<Bomb>(ObjectGroup::Bomb);
		NewBomb->Set_Pt(Get_Pt());
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

	IsItem(Get_Pt());
}

Player::Player()
{
	Point ScreenSize = ConsoleGameScreen::Get_MainScreen().Get_Size();

	Set_Pt({ ScreenSize.x / 2, ScreenSize.y - 1 });
	Set_RenderChar('*');
}

bool Player::IsBomb(const Point& _pt) const
{
	list<Object*>& Group = ObjectManager::Get_ObjectGroup(ObjectGroup::Bomb);

	for (auto obj : Group)
	{
		if (obj->Get_Pt() == _pt)
		{
			return true;
		}
	}

	return false;
}

void Player::IsItem(const Point& _pt) const
{
	list<Object*>& Group = ObjectManager::Get_ObjectGroup(ObjectGroup::Item);

	for (auto obj : Group)
	{
		if (obj->Get_Pt() == _pt)
		{
			obj->Set_Active(false);
			Bomb::Set_MaxPower(Bomb::Get_MaxPower() + 1);
		}
	}
}