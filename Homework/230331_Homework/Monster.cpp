#include "Monster.h"

#include "ConsoleGameScreen.h"

Monster Monster::ArrMonster[Monster::ArrMonsterCount];
int Monster::Dir = -1;
int Monster::Tick = 0;

void Monster::AllUpdate()
{
	for (int i = 0; i < Monster::ArrMonsterCount; i++)
	{
		if (!ArrMonster[i].GetUpdateValue())
		{
			continue;
		}

		if (ConsoleGameScreen::Instance().IsScreenOver(ArrMonster[i].Pos))
		{
			ArrMonster[i].SetUpdateValue(false);
		}

		Point NextPos = ArrMonster[i].Pos;
		NextPos.x += Dir;
		if (ConsoleGameScreen::Instance().IsScreenOver(NextPos))
		{
			Dir *= -1;
			for (int j = 0; j < Monster::ArrMonsterCount; j++)
			{
				ArrMonster[j].Pos.y += 1;
			}
		}

		if (Tick % 4 == 0)
		{
			ArrMonster[i].Pos.x += Dir;
			Tick = 0;
		}
	}

	++Tick;
}

void Monster::AllRender()
{
	for (int i = 0; i < Monster::ArrMonsterCount; i++)
	{
		if (!ArrMonster[i].GetUpdateValue())
		{
			continue;
		}

		ArrMonster[i].Render();
	}
}

Monster::Monster()
{
	RenderChar = 'M';
}
