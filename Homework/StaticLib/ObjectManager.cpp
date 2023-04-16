#include "ObjectManager.h"

#include "ConsoleGameScreen.h"

vector<list<Object*>> ObjectManager::AllObject;

void ObjectManager::Update()
{
	for (auto& group : AllObject)
	{
		for (auto obj : group)
		{
			if (!obj->Get_Active())
			{
				continue;
			}

			obj->Update();
		}
	}
}

void ObjectManager::Release()
{
	for (auto& group : AllObject)
	{
		for (auto iter = group.begin(); iter != group.end();)
		{
			if (!(*iter)->Get_Active())
			{
				delete (*iter);
				*iter = nullptr;
				iter = group.erase(iter);
			}
			else
			{
				++iter;
			}
		}
	}
}

void ObjectManager::Delete()
{
	for (auto& group : AllObject)
	{
		for (auto obj : group)
		{
			if (obj)
			{
				delete obj;
				obj = nullptr;
			}
		}
	}
}
