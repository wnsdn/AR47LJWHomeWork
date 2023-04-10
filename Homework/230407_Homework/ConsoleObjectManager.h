#pragma once

#include <GameEngineLib/GameEngineArray.h>
#include <GameEngineLib/GameEngineObject.h>

class ConsoleObjectManager
{
public:
	template <typename ObjectType>
	static ObjectType* CreateConsoleObject(int _order)
	{
		if (_order >= AllObject.Size())
		{
			AllObject.Resize(_order + 1);
		}

		GameEngineArray<GameEngineObject*>& Group = AllObject[_order];
		ObjectType* NewObject = new ObjectType();
		Group.Resize(Group.Size() + 1);
		Group[Group.Size() - 1] = NewObject;

		return NewObject;
	}

	template <typename ObjectType, typename EnumType>
	static ObjectType* CreateConsoleObject(EnumType _order)
	{
		return CreateConsoleObject<ObjectType>((int)_order);
	}

	static GameEngineArray<GameEngineObject*>& GetGroup(int _order)
	{
		return AllObject[_order];
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectDelete();
protected:

private:
	static GameEngineArray<GameEngineArray<GameEngineObject*>> AllObject;

	ConsoleObjectManager();
	~ConsoleObjectManager();

	ConsoleObjectManager(const ConsoleObjectManager& _ref) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _ref) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _ref) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _ref) noexcept = delete;
};

