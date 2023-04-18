#include "ConsoleGameScreen.h"

#include <iostream>

ConsoleGameScreen ConsoleGameScreen::instance;

void ConsoleGameScreen::ScreenClear()
{
	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint()
{
	for (int y = 0; y < ScreenY; y++)
	{
		for (int x = 0; x < ScreenX; x++)
		{
			printf_s("%c", arr[y][x]);
		}
		putchar('\n');
	}
}

void ConsoleGameScreen::SetCharacter(const Point& _pos, char _ch)
{
	if (IsScreenOver(_pos))
	{
		return;
	}

	arr[_pos.y][_pos.x] = _ch;
}

bool ConsoleGameScreen::IsScreenOver(const Point& _pos) const
{
	if (_pos.x >= 0 && _pos.x < ScreenX
		&& _pos.y >= 0 && _pos.y < ScreenY)
	{
		return false;
	}
	else
	{
		return true;
	}
}
