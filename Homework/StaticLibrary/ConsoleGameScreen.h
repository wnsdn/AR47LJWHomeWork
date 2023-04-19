#pragma once

#include <vector>
#include <string>

#include "Struct.h"

using std::vector;
using std::wstring;

class ConsoleGameScreen
{
public:
	void Update();
	void Render() const;

	bool IsOutOfScreen(const Point& _pt)
	{
		if (_pt.x >= 0 && _pt.x < ScreenSize.x &&
			_pt.y >= 0 && _pt.y < ScreenSize.y)
		{
			return false;
		}

		return true;
	}

	static ConsoleGameScreen& GetMainScreen()
	{
		return s_MainScreen;
	}

	wchar_t GetScreenChar(const Point& _pt) const
	{
		return ScreenChar[_pt.y][_pt.x];
	}
	void SetScreenChar(const Point& _pt, const wchar_t _ScreenChar)
	{
		ScreenChar[_pt.y][_pt.x] = _ScreenChar;
	}

	const Point& GetScreenSize() const
	{
		return ScreenSize;
	}
	void SetScreenSize(const Point& _Size)
	{
		ScreenChar.resize(_Size.y, vector<wchar_t>(_Size.x));

		ScreenSize = _Size;
	}

	int GetScreenUpdateRate() const
	{
		return ScreenUpdateRate;
	}
	void SetScreenUpdateRate(const int _ScreenUpdateRate)
	{
		ScreenUpdateRate = _ScreenUpdateRate;
	}

private:
	static ConsoleGameScreen s_MainScreen;

	vector<vector<wchar_t>> ScreenChar;
	Point ScreenSize;
	int ScreenUpdateRate;

	ConsoleGameScreen()
		: ScreenChar()
		, ScreenSize(0, 0)
		, ScreenUpdateRate(0)
	{}
	~ConsoleGameScreen() {}
	ConsoleGameScreen(const ConsoleGameScreen& _ref) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _ref) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _ref) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _ref) noexcept = delete;
};
