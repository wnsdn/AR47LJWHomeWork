#include "ConsoleObjectManager.h"

#include <StaticLib/ConsoleGameScreen.h>

GameEngineArray<GameEngineArray<ConsoleGameObject*>> ConsoleObjectManager::AllObject;

void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); ++GroupIndex)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ++ObjectIndex)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->GetUpdate())
			{
				continue;
			}

			Object->Update();
		}
	}
}

void ConsoleObjectManager::ConsoleAllObjectRender()
{
	ConsoleGameScreen::GetMainScreen().ScreenClear();

	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); ++GroupIndex)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ++ObjectIndex)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->GetUpdate())
			{
				continue;
			}

			Object->Render();
		}
	}

	ConsoleGameScreen::GetMainScreen().ScreenPrint();
}

void ConsoleObjectManager::ConsoleAllObjectRelease()
{
	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); GroupIndex++)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ObjectIndex++)
		{
			ConsoleGameObject*& Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->GetDeath())
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}

	}
}

void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); ++GroupIndex)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ++ObjectIndex)
		{
			ConsoleGameObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object)
			{
				continue;
			}

			delete Object;
			Object = nullptr;
		}
	}
}

ConsoleObjectManager::ConsoleObjectManager()
{
}

ConsoleObjectManager::~ConsoleObjectManager()
{
}
