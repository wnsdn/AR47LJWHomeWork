#include <crtdbg.h>

#include <StaticLibrary/ConsoleGameScreen.h>
#include <StaticLibrary/ObjectManager.h>
#include <StaticLibrary/Random.h>

#include "Player.h"
#include "Item.h"
#include "Enum.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(186);
	Random::Init();
	ConsoleGameScreen::GetMainScreen().Init({ 20, 10 });

	ConsoleGameScreen::GetMainScreen().Render();

	/*ObjectManager::Init(ObjectGroup::End);

	ObjectManager::InsertObject<Player>(ObjectGroup::Player);

	ObjectManager::InsertObject<Item>(ObjectGroup::Item);
	ObjectManager::InsertObject<Item>(ObjectGroup::Item);
	ObjectManager::InsertObject<Item>(ObjectGroup::Item);*/

	/*while (Player::IsGameUpdate)
	{
		ConsoleGameScreen::GetMainScreen().Update();

		ObjectManager::Update();
		ObjectManager::Release();

		ConsoleGameScreen::GetMainScreen().Render();
	}

	ObjectManager::Delete();*/

	return 0;
}