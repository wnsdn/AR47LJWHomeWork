#include "Bomb.h"

#include <StaticLib/ConsoleGameScreen.h>

int Bomb::m_MaxPower = 1;

void Bomb::Update()
{
	Object::Update();

	if (m_CurPower == m_MaxPower)
	{
		Set_Active(false);
	}

	if (m_Count-- <= 0)
	{
		++m_CurPower;
	}

	for (int i = 0; i < m_CurPower; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			Point DirPt = Get_Pt() + Point::Dir[j] * i;
			ConsoleGameScreen::Get_MainScreen().Set_ScreenChar(DirPt, '#');
		}
	}
}