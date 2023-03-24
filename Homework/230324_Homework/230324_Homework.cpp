#include <iostream>
#include <conio.h>

int main()
{
	const int ScreenYSize = 5;
	const int ScreenXSize = 10;

	char Arr[ScreenYSize][ScreenXSize] = { 0, };

	for (size_t y = 0; y < ScreenYSize; y++)
	{
		for (size_t x = 0; x < ScreenXSize; x++)
		{
			Arr[y][x] = 'a';
		}
	}

	int PlayerY = ScreenYSize / 2;
	int PlayerX = ScreenXSize / 2;

	while (true)
	{
		system("cls");

		for (size_t y = 0; y < ScreenYSize; y++)
		{
			for (size_t x = 0; x < ScreenXSize; x++)
			{
				if (x == PlayerX && y == PlayerY)
				{
					putchar('*');
				}
				else
				{
					printf_s("%c", Arr[y][x]);
				}
			}
			printf_s("\n");
		}

		char Ch = _getch();

		switch (Ch)
		{
		case 'a':
		case 'A':
		{
			if (PlayerX > 0)
			{
				PlayerX -= 1;
			}
			break;
		}
		case 'd':
		case 'D':
		{
			if (PlayerX < ScreenXSize - 1)
			{
				PlayerX += 1;
			}
			break;
		}
		case 'w':
		case 'W':
		{
			if (PlayerY > 0)
			{
				PlayerY -= 1;
			}
			break;
		}
		case 's':
		case 'S':
		{
			if (PlayerY < ScreenYSize - 1)
			{
				PlayerY += 1;
			}
			break;
		}
		default:
			break;
		}
	}


}
