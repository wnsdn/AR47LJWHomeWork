#include "ConsoleGameScreen.h"

#include <Windows.h>

ConsoleGameScreen ConsoleGameScreen::s_MainScreen;

void ConsoleGameScreen::Update()
{
	for (int y = 0; y < m_Size.y; ++y)
	{
		for (int x = 0; x < m_Size.x; ++x)
		{
			m_Screen[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::Render() const
{
	system("cls");

	for (int y = 0; y < m_Size.y; ++y)
	{
		for (int x = 0; x < m_Size.x; ++x)
		{
			printf_s("%c", m_Screen[y][x]);
		}

		putchar('\n');
	}

	Sleep(m_ScreenUpdateRate);
}
