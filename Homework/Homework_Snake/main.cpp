#include <crtdbg.h>

#include <StaticLibrary/ConsoleGameScreen.h>
#include <StaticLibrary/ObjectManager.h>
#include <StaticLibrary/Random.h>

#include "Enum.h"
#include "Snake.h"
#include "Parts.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(169);

	ConsoleGameScreen::GetMainScreen().SetScreenSize({ 5, 5 });
	ConsoleGameScreen::GetMainScreen().SetScreenUpdateRate(200);

	ObjectManager::Init(ObjectGroup::End);
	ObjectManager::InsertObject<Snake>(ObjectGroup::Snake);

	Random::Init();
	Point MaxPoint = ConsoleGameScreen::GetMainScreen().GetScreenSize() - 1;
	Point MinPoint = { 0, 0 };

	while (Snake::IsGameUpdate)
	{
		ConsoleGameScreen::GetMainScreen().Update();

		ObjectManager::Progress();
		if (ObjectManager::GetGroupSize(ObjectGroup::Parts) <= 0)
		{
			ObjectManager::InsertObject<Parts>(ObjectGroup::Parts)->SetPoint(Random::RandomPoint(MaxPoint, MinPoint));
		}
		ObjectManager::Release();

		if (Snake::Win)
		{
			break;
		}

		ConsoleGameScreen::GetMainScreen().Render();
	}

	ObjectManager::Delete();

	system("cls");

	if (Snake::Win)
	{
		printf_s("\n=== WIN !!! ===\n");
		return 0;
	}

	if (!Snake::IsGameUpdate)
	{
		printf_s("\n=== Game Over ===\n");
	}

	return 0;
}