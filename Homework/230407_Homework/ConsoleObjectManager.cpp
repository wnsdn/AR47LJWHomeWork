#include "ConsoleObjectManager.h"

#include <GameEngineLib/GameEngineScreen.h>

GameEngineArray<GameEngineArray<GameEngineObject*>> ConsoleObjectManager::AllObject;

void ConsoleObjectManager::ConsoleAllObjectUpdate()
{
	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); ++GroupIndex)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ++ObjectIndex)
		{
			GameEngineObject* Object = AllObject[GroupIndex][ObjectIndex];

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
	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); ++GroupIndex)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ++ObjectIndex)
		{
			GameEngineObject* Object = AllObject[GroupIndex][ObjectIndex];

			if (nullptr == Object || false == Object->GetUpdate())
			{
				continue;
			}

			Object->Render();
		}
	}
}

void ConsoleObjectManager::ConsoleAllObjectDelete()
{
	for (int GroupIndex = 0; GroupIndex < AllObject.Size(); ++GroupIndex)
	{
		for (int ObjectIndex = 0; ObjectIndex < AllObject[GroupIndex].Size(); ++ObjectIndex)
		{
			GameEngineObject* Object = AllObject[GroupIndex][ObjectIndex];

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
