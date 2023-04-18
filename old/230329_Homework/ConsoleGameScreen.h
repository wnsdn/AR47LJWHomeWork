#pragma once
#include "ConsoleGameMath.h"

class ConsoleGameScreen
{
public:
	static ConsoleGameScreen& GetMainScreen()
	{
		static ConsoleGameScreen MainScreen;
		return MainScreen;
	}

	Point GetScreenSize() const
	{
		return { ScreenxSize, ScreenySize };
	}

	void ScreenClear();
	void ScreenPrint() const;
	bool IsScreenOver(const Point& _Pos) const;
	void SetScreenCharacter(const Point& _Pos, char _Ch);
	void SetScreenBullet(const Point& _Pos, char _Ch);

private:
	static const int ScreenySize = 10;
	static const int ScreenxSize = 20;
	char Arr[ScreenySize][ScreenxSize] = {};

	ConsoleGameScreen();
};