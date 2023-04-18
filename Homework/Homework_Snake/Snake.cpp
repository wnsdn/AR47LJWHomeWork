#include "Snake.h"

#include <conio.h>

#include <StaticLibrary/ConsoleGameScreen.h>
#include <StaticLibrary/ObjectManager.h>

#include "Enum.h"

bool Snake::IsGameUpdate = true;

bool Snake::Win = false;

void Snake::Update()
{
	Point ScreenSize = ConsoleGameScreen::GetMainScreen().GetScreenSize();
	if (Body.size() + 1 >= ScreenSize.x * ScreenSize.y)
	{
		Win = true;
	}

	if (!_kbhit())
	{
		return;
	}

	Point PrevPoint = GetPoint();
	int PrevDirection = Direction;
	for (int i = 0; i < Body.size(); ++i)
	{
		std::get<0>(Body[i]) = PrevPoint;
		PrevPoint = std::get<1>(Body[i]);

		std::get<2>(Body[i]) = PrevDirection;
		PrevDirection = std::get<3>(Body[i]);
	}

	switch (_getch())
	{
	case 'w':
	case 'W':
	{
		Direction = 0;
		break;
	}
	case 's':
	case 'S':
	{
		Direction = 1;
		break;
	}
	case 'a':
	case 'A':
	{
		Direction = 2;
		break;
	}
	case 'd':
	case 'D':
	{
		Direction = 3;
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	}

	SetPoint(GetPoint() + Point::Dir[Direction]);
	SetRenderChar(HeadChar[Direction]);

	for (int i = 0; i < Body.size(); ++i)
	{
		std::get<1>(Body[i]) = std::get<0>(Body[i]);
		std::get<3>(Body[i]) = std::get<2>(Body[i]);
	}

	for (auto _parts : ObjectManager::GetObjectGroup(ObjectGroup::Parts))
	{
		if (_parts->GetPoint() == GetPoint())
		{
			_parts->SetActive(false);
			Body.push_back(std::make_tuple(PrevPoint, PrevPoint, PrevDirection, PrevDirection));
		}
	}

	for (auto& _body : Body)
	{
		if (GetPoint() == std::get<1>(_body))
		{
			IsGameUpdate = false;
		}
	}

	if (ConsoleGameScreen::GetMainScreen().IsOutOfScreen(GetPoint()))
	{
		IsGameUpdate = false;
	}
}

void Snake::Render()
{
	Object::Render();

	for (int i = 0; i < Body.size(); ++i)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenChar(std::get<1>(Body[i]), BodyChar[std::get<3>(Body[i])]);
	}
}

void Snake::Delete()
{
	Body.clear();
}

Snake::Snake()
	: Direction(0)
{
	Point Position;
	Position.x = ConsoleGameScreen::GetMainScreen().GetScreenSize().x / 2;
	Position.y = ConsoleGameScreen::GetMainScreen().GetScreenSize().y / 2;
	SetPoint(Position);
	SetRenderChar(L'бу');
}
