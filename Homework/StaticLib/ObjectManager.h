#pragma once

#include <vector>
#include <list>

#include "Object.h"

using std::vector;
using std::list;

class ObjectManager
{
public:
	template <typename DataType>
	static void Init(DataType _size)
	{
		AllObject.resize((int)_size);
	}
	static void Update();
	static void Release();
	static void Delete();

	template <typename ObjectType, typename DataType>
	static ObjectType* InsertObject(DataType _group)
	{
		ObjectType* NewObject = new ObjectType;
		AllObject[(int)_group].push_back(NewObject);

		return NewObject;
	}

	template <typename DataType>
	static list<Object*>& Get_ObjectGroup(DataType _group)
	{
		return AllObject[(int)_group];
	}
private:
	static vector<list<Object*>> AllObject;

	ObjectManager() {}
	~ObjectManager() {}

	ObjectManager(const ObjectManager& _ref) = delete;
	ObjectManager(ObjectManager&& _ref) noexcept = delete;
	ObjectManager& operator=(const ObjectManager& _ref) = delete;
	ObjectManager& operator=(ObjectManager&& _ref) noexcept = delete;
};
