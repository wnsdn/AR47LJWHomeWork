#include "Bomb.h"

#include <GameEngineLib/GameEngineScreen.h>

void Bomb::Init()
{
	SetRenderChar('@');
}

void Bomb::Update()
{
	GameEngineObject::Update();

	if (0 >= --BoomCount)
	{
		SetUpdate(false);

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < Length; ++j)
			{
				int2 BoomPos = GetPos() + index[i] * j;
				GameEngineScreen::GetMainScreen().SetScreenCharacter(BoomPos, '#');
			}
		}
	}
}

void Bomb::Render()
{
	GameEngineObject::Render();
}

Bomb::Bomb()
{
}

Bomb::~Bomb()
{
}
