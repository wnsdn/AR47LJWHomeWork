#pragma once

#include "GameEngineMath.h"
#include "GameEngineArray.h"

class GameEngineScreen
{
public:
	static GameEngineScreen& GetMainScreen()
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
	static GameEngineScreen MainScreen;

	GameEngineArray<GameEngineArray<char>> m_Arr;
	int2 m_Size;

	GameEngineScreen();
	~GameEngineScreen();
	GameEngineScreen(const GameEngineScreen& _ref) = delete;
	GameEngineScreen(GameEngineScreen&& _ref) noexcept = delete;
	GameEngineScreen& operator=(const GameEngineScreen& _ref) = delete;
	GameEngineScreen& operator=(GameEngineScreen&& _ref) noexcept = delete;
};

