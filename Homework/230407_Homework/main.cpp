#include <iostream>

#include <GameEngineLib/GameEngineDebug.h>
#include <GameEngineLib/GameEngineMath.h>
#include <GameEngineLib/GameEngineScreen.h>
#include "ConsoleObjectManager.h"
#include "GameEnum.h"
#include "Player.h"

int main()
{
	GameEngineDebug::LeakCheck();

	int2 ScreenSize = { 20, 10 };
	GameEngineScreen::GetMainScreen().SetScreenSize(ScreenSize);

	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);

	while (Player::IsGameUpdate)
	{
		GameEngineScreen::GetMainScreen().ScreenClear();

		ConsoleObjectManager::ConsoleAllObjectUpdate();
		ConsoleObjectManager::ConsoleAllObjectRender();

		GameEngineScreen::GetMainScreen().ScreenPrint();

		Sleep(200);
	}

	ConsoleObjectManager::ConsoleAllObjectDelete();

	return 0;
}