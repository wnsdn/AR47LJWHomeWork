//#include <iostream>
//
//#include <StaticLib/GameEngineDebug.h>
//#include <StaticLib/ConsoleGameMath.h>
//#include <StaticLib/ConsoleGameScreen.h>
//
//#include "ConsoleObjectManager.h"
//#include "GameEnum.h"
//#include "Player.h"
//
//int main()
//{
//	GameEngineDebug::LeakCheck();
//
//	int2 ScreenSize = { 20, 10 };
//	ConsoleGameScreen::GetMainScreen().SetScreenSize(ScreenSize);
//
//	ConsoleObjectManager::CreateConsoleObject<Player>(ObjectOrder::Player);
//
//	while (Player::IsGameUpdate)
//	{
//		ConsoleObjectManager::ConsoleAllObjectUpdate();
//		ConsoleObjectManager::ConsoleAllObjectRender();
//		ConsoleObjectManager::ConsoleAllObjectRelease();
//		Sleep(200);
//	}
//
//	ConsoleObjectManager::ConsoleAllObjectDelete();
//
//	return 0;
//}