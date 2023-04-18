#include "ConsoleGameScreen.h"

#include <Windows.h>
#include <iostream>

ConsoleGameScreen ConsoleGameScreen::s_MainScreen;

void ConsoleGameScreen::Update()
{
	for (int y = 0; y < ScreenSize.y; ++y)
	{
		for (int x = 0; x < ScreenSize.x; ++x)
		{
			ScreenChar[y][x] = L'бр';
		}
	}
}

void ConsoleGameScreen::Render() const
{
	system("cls");

	setlocale(LC_ALL, "KOR");
	for (auto& y : ScreenChar)
	{
		for (auto x : y)
		{
			wprintf_s(L"%c", x);
		}

		putchar('\n');
	}

	Sleep(ScreenUpdateRate);
}
