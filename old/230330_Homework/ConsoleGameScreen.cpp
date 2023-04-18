#include "ConsoleGameScreen.h"
#include <iostream>

ConsoleGameScreen::ConsoleGameScreen()
{
}

void ConsoleGameScreen::ScreenClear()
{
	for (size_t y = 0; y < ScreenySize; y++)
	{
		for (size_t x = 0; x < ScreenxSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}
}

void ConsoleGameScreen::ScreenPrint() const
{
	for (size_t y = 0; y < ScreenySize; y++)
	{
		for (size_t x = 0; x < ScreenxSize; x++)
		{
			printf_s("%c", Arr[y][x]);
		}
		printf_s("\n");
	}
}

bool ConsoleGameScreen::IsScreenOver(const Point& _Pos) const
{
	if (0 > _Pos.x)
	{
		return true;
	}

	if (0 > _Pos.y)
	{
		return true;
	}

	if (ScreenxSize <= _Pos.x)
	{
		return true;
	}

	if (ScreenySize <= _Pos.y)
	{
		return true;
	}

	return false;
}

void ConsoleGameScreen::SetScreenCharacter(const Point& _Pos, char _Ch)
{
	if (true == IsScreenOver(_Pos))
	{
		return;
	}

	Arr[_Pos.y][_Pos.x] = _Ch;
}