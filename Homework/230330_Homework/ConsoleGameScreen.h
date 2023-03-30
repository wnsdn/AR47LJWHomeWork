#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
	static const int InterFrame = 160;

	void ScreenClear();
	void ScreenPrint() const;
	bool IsScreenOver(const Point& _Pos) const;
	void SetScreenCharacter(const Point& _Pos, char _Ch);

	static ConsoleGameScreen& Instance()
	{
		static ConsoleGameScreen MainScreen;
		return MainScreen;
	}

	Point GetScreenSize() const
	{
		return { ScreenxSize, ScreenySize };
	}

private:
	static const int ScreenySize = 10;
	static const int ScreenxSize = 20;

	char Arr[ScreenySize][ScreenxSize] = {};

	ConsoleGameScreen();
};