﻿#include <iostream>
#include <conio.h>
#include <Windows.h>

class int2
{
public:
	int X = 0;
	int Y = 0;

public:
	int2 Half()
	{
		return { X / 2, Y / 2 };
	}

public:

	int2(int _X, int _Y)
		: X(_X), Y(_Y)
	{

	}
};

class ConsoleGameScreen
{
public:
	static const int ScreenYSize = 10;
	static const int ScreenXSize = 20;

	static int2 GetScreenSize()
	{
		return int2{ ScreenXSize, ScreenYSize };
	}

	void ScreenClear()
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				Arr[y][x] = 'a';
			}
		}
	}

	void ScreenPrint() const
	{
		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				printf_s("%c", Arr[y][x]);
			}
			printf_s("\n");
		}
	}

	// 이녀석을 무조건 사용해서 플레이어가 바깥으로 못나가게 만드세요.
	int IsScreenOver(const int2& _Pos)
	{
		if (0 > _Pos.X)
		{
			return 1;
		}

		if (0 > _Pos.Y)
		{
			return 2;
		}

		if (ScreenXSize <= _Pos.X)
		{
			return 3;
		}

		if (ScreenYSize <= _Pos.Y)
		{
			return 4;
		}

		return 0;
	}

	void SetScreenCharacter(const int2& _Pos, char _Ch)
	{
		/*if (true == IsScreenOver(_Pos))
		{
			return;
		}*/

		Arr[_Pos.Y][_Pos.X] = _Ch;
	}

private:
	char Arr[ScreenYSize][ScreenXSize] = { 0, };

};

class Player
{
public:
	int2 GetPos() const
	{
		return Pos;
	}
	int GetPosX() const
	{
		return Pos.X;
	}
	int GetPosY() const
	{
		return Pos.Y;
	}

	void SetPos(const int2& _Value)
	{
		Pos = _Value;
	}
	void SetPosX(const int _X)
	{
		Pos.X = _X;
	}
	void SetPosY(const int _Y)
	{
		Pos.Y = _Y;
	}

	void Input()
	{
		/*if (0 == _kbhit())
		{
			Sleep(InterFrame);
			return;
		}*/

		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
			Pos.X -= 1;
			break;
		case 'd':
		case 'D':
			Pos.X += 1;
			break;
		case 'w':
		case 'W':
			Pos.Y -= 1;
			break;
		case 's':
		case 'S':
			Pos.Y += 1;
			break;
		default:
			break;
		}

		//Sleep(InterFrame);
	}
private:
	static const int InterFrame = 50;

	int2 Pos = int2(0, 0);
};

int main()
{
	ConsoleGameScreen NewScreen;
	Player NewPlayer;

	int2 ScreenSize = NewScreen.GetScreenSize();
	NewPlayer.SetPos(ScreenSize.Half());

	while (true)
	{
		system("cls");

		NewScreen.ScreenClear();

		NewScreen.SetScreenCharacter(NewPlayer.GetPos(), '*');

		NewScreen.ScreenPrint();
		
		NewPlayer.Input();

		int PlayerPosX = NewPlayer.GetPosX();
		int PlayerPosY = NewPlayer.GetPosY();
		switch (NewScreen.IsScreenOver(NewPlayer.GetPos()))
		{
		case 1:
			NewPlayer.SetPosX(PlayerPosX + 1);
			break;
		case 2:
			NewPlayer.SetPosY(PlayerPosY + 1);
			break;
		case 3:
			NewPlayer.SetPosX(PlayerPosX - 1);
			break;
		case 4:
			NewPlayer.SetPosY(PlayerPosY - 1);
			break;
		}
	}
}