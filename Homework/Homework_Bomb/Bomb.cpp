#include "Bomb.h"

#include <StaticLibrary/ConsoleGameScreen.h>

int Bomb::m_Power = 1;

void Bomb::Update()
{
	Object::Update();

	if (m_CurPower == m_MaxPower)
	{
		SetActive(false);
	}

	if (m_Count-- <= 0)
	{
		++m_CurPower;
	}

	for (int i = 0; i < m_CurPower; ++i)
	{
		ConsoleGameScreen::GetMainScreen().SetScreenChar(GetPoint() + Point::Left * i, '#');
		ConsoleGameScreen::GetMainScreen().SetScreenChar(GetPoint() + Point::Right * i, '#');
		ConsoleGameScreen::GetMainScreen().SetScreenChar(GetPoint() + Point::Up * i, '#');
		ConsoleGameScreen::GetMainScreen().SetScreenChar(GetPoint() + Point::Down * i, '#');
	}
}