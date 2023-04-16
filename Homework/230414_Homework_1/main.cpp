#include <crtdbg.h>

#include <StaticLib/ConsoleGameScreen.h>
#include <StaticLib/ObjectManager.h>

#include "Player.h"
#include "Item.h"
#include "Enum.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(186);

	ObjectManager::Init(ObjectGroup::End);

	ObjectManager::InsertObject<Player>(ObjectGroup::Player);

	ObjectManager::InsertObject<Item>(ObjectGroup::Item);
	ObjectManager::InsertObject<Item>(ObjectGroup::Item);
	ObjectManager::InsertObject<Item>(ObjectGroup::Item);

	while (Player::IsGameUpdate)
	{
		ConsoleGameScreen::Get_MainScreen().Update();

		ObjectManager::Update();
		ObjectManager::Release();

		ConsoleGameScreen::Get_MainScreen().Render();
	}

	ObjectManager::Delete();

	return 0;
}