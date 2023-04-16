#pragma once

#include "ConsoleGameMath.h"
#include "GameEngineArray.h"

class ConsoleGameScreen
{
public:
	static ConsoleGameScreen& GetMainScreen()
	{
		return MainScreen;
	}

	void SetScreenSize(const int2& _size);
	int2 GetScreenSize() const
	{
		return m_Size;
	}

	void ScreenClear();
	void ScreenPrint() const;
	bool IsScreenOver(const int2& _pos) const;
	void SetScreenCharacter(const int2& _pos, const char _ch) const;
protected:

private:
	static ConsoleGameScreen MainScreen;

	GameEngineArray<GameEngineArray<char>> m_Arr;
	int2 m_Size;

	ConsoleGameScreen();
	~ConsoleGameScreen();
	ConsoleGameScreen(const ConsoleGameScreen& _ref) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _ref) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _ref) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _ref) noexcept = delete;
};

