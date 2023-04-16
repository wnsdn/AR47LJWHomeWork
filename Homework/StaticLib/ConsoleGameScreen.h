#pragma once

#include <vector>

#include "Struct.h"

using std::vector;

class ConsoleGameScreen
{
public:
	void Update();
	void Render() const;

	bool IsOutOfScreen(const Point& _pt)
	{
		if (_pt.x >= 0 && _pt.x < m_Size.x &&
			_pt.y >= 0 && _pt.y < m_Size.y)
		{
			return false;
		}

		return true;
	}

	static ConsoleGameScreen& Get_MainScreen()
	{
		return s_MainScreen;
	}

	const Point& Get_Size() const
	{
		return m_Size;
	}
	void Set_Size(const Point& _Size)
	{
		m_Screen.resize(_Size.y, vector<char>(_Size.x));

		m_Size = _Size;
	}
	void Set_Size(const int _x, const int _y)
	{
		m_Screen.resize(_y, vector<char>(_x));

		m_Size.x = _x;
		m_Size.y = _y;
	}

	void Set_ScreenChar(const Point& _pt, const char _ch)
	{
		if (IsOutOfScreen(_pt))
		{
			return;
		}
		m_Screen[_pt.y][_pt.x] = _ch;
	}

	int Get_ScreenUpdateRate() const
	{
		return m_ScreenUpdateRate;
	}
	void Set_ScreenUpdateRate(const int _ScreenUpdateRate)
	{
		m_ScreenUpdateRate = _ScreenUpdateRate;
	}

private:
	static ConsoleGameScreen s_MainScreen;

	vector<vector<char>> m_Screen;
	Point m_Size;
	int m_ScreenUpdateRate;

	ConsoleGameScreen() 
		: m_Screen()
		, m_Size(20, 10)
		, m_ScreenUpdateRate(150)
	{
		m_Screen.resize(m_Size.y, vector<char>(m_Size.x));
	}
	~ConsoleGameScreen() {}
	ConsoleGameScreen(const ConsoleGameScreen& _ref) = delete;
	ConsoleGameScreen(ConsoleGameScreen&& _ref) noexcept = delete;
	ConsoleGameScreen& operator=(const ConsoleGameScreen& _ref) = delete;
	ConsoleGameScreen& operator=(ConsoleGameScreen&& _ref) noexcept = delete;
};
