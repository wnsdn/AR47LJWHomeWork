#include <crtdbg.h>

#include <StaticLib/ConsoleGameScreen.h>
#include <StaticLib/ObjectManager.h>
#include <StaticLib/Random.h>

#include "Head.h"
#include "Item.h"
#include "Enum.h"

int Count = 0;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(178);
	Random::Init();
	ConsoleGameScreen::Get_MainScreen().Set_Size(4, 2);

	ObjectManager::Init(ObjectGroup::End);

	ObjectManager::InsertObject<Head>(ObjectGroup::Head);

	while (Head::IsGameUpdate)
	{
		if (Count % 15 == 0)
		{
			if (ObjectManager::Get_GroupSize(ObjectGroup::Item) < 1)
			{
				ObjectManager::InsertObject<Item>(ObjectGroup::Item);
			}

			Count = 0;
		}

		ConsoleGameScreen::Get_MainScreen().Update();

		ObjectManager::Update();
		ObjectManager::Release();

		ConsoleGameScreen::Get_MainScreen().Render();
		++Count;

		if (Head::Win)
		{
			break;
		}
	}

	ObjectManager::Delete();

	if (Head::Win)
	{
		system("cls");
		printf_s("\n==== Win ====\n");
	}

	return 0;
}