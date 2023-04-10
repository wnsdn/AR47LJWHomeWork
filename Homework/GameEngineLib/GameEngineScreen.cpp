#include "GameEngineScreen.h"

#include <iostream>

GameEngineScreen GameEngineScreen::MainScreen;

void GameEngineScreen::SetScreenSize(const int2& _size)
{
	m_Size = _size;

	m_Arr.Resize(m_Size.y);
	for (int i = 0; i < m_Size.y; ++i)
	{
		m_Arr[i].Resize(m_Size.x);
	}
}

void GameEngineScreen::ScreenClear()
{
	system("cls");

	for (int y = 0; y < m_Size.y; ++y)
	{
		for (int x = 0; x < m_Size.x; ++x)
		{
			m_Arr[y][x] = 'a';
		}
	}
}

void GameEngineScreen::ScreenPrint() const
{
	for (int y = 0; y < m_Size.y; ++y)
	{
		for (int x = 0; x < m_Size.x; ++x)
		{
			printf_s("%c", m_Arr[y][x]);
		}

		putchar('\n');
	}
}

bool GameEngineScreen::IsScreenOver(const int2& _pos) const
{
	if (_pos.x >= 0 && _pos.x < m_Size.x &&
		_pos.y >= 0 && _pos.y < m_Size.y)
	{
		return false;
	}

	return true;
}

void GameEngineScreen::SetScreenCharacter(const int2& _pos, const char _ch) const
{
	if (true == IsScreenOver(_pos))
	{
		return;
	}

	m_Arr[_pos.y][_pos.x] = _ch;
}

GameEngineScreen::GameEngineScreen()
{
}

GameEngineScreen::~GameEngineScreen()
{
}
