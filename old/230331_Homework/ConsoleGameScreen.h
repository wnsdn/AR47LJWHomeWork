#pragma once
#include "Struct.h"

class ConsoleGameScreen
{
public:
	static const int ScreenX = 20;
	static const int ScreenY = 10;

	static ConsoleGameScreen& Instance()
	{
		return instance;
	}

	void ScreenClear();
	void ScreenPrint();
	void SetCharacter(const Point& _pos, char _ch);
	bool IsScreenOver(const Point& _pos) const;
private:
	static ConsoleGameScreen instance;
	char arr[ScreenY][ScreenX];

	ConsoleGameScreen() {}
};

