#pragma once

#include <StaticLib/GameEngineArray.h>
#include <StaticLib/ConsoleGameObject.h>

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

		GameEngineArray<ConsoleGameObject*>& Group = AllObject[_order];
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

	template <typename EnumType>
	static GameEngineArray<ConsoleGameObject*>& GetGroup(EnumType _order)
	{
		return AllObject[(int)_order];
	}

	static GameEngineArray<ConsoleGameObject*>& GetGroup(int _order)
	{
		return AllObject[_order];
	}

	static void ConsoleAllObjectUpdate();
	static void ConsoleAllObjectRender();
	static void ConsoleAllObjectRelease();
	static void ConsoleAllObjectDelete();
protected:

private:
	static GameEngineArray<GameEngineArray<ConsoleGameObject*>> AllObject;

	ConsoleObjectManager();
	~ConsoleObjectManager();

	ConsoleObjectManager(const ConsoleObjectManager& _ref) = delete;
	ConsoleObjectManager(ConsoleObjectManager&& _ref) noexcept = delete;
	ConsoleObjectManager& operator=(const ConsoleObjectManager& _ref) = delete;
	ConsoleObjectManager& operator=(ConsoleObjectManager&& _ref) noexcept = delete;
};

