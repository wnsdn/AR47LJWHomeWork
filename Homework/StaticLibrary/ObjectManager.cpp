#include "ObjectManager.h"

#include "ConsoleGameScreen.h"

vector<list<Object*>> ObjectManager::AllObject;

void ObjectManager::Progress()
{
	for (auto& group : AllObject)
	{
		for (auto obj : group)
		{
			if (!obj->GetActive())
			{
				continue;
			}

			obj->Update();
			obj->Render();
		}
	}
}

void ObjectManager::Release()
{
	for (auto& group : AllObject)
	{
		for (auto iter = group.begin(); iter != group.end();)
		{
			if (!(*iter)->GetActive())
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
				obj->Delete();

				delete obj;
				obj = nullptr;
			}
		}
	}
}
