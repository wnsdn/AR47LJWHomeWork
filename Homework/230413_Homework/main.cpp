#include <iostream>
#include <list>

#include <StaticLib/GameEngineDebug.h>
#include <StaticLib/GameEngineList.h>

int main()
{
	GameEngineDebug::LeakCheck();

	GameEngineList<int> NewList;

	NewList.push_back(10);
	NewList.push_back(20);
	NewList.push_back(30);
	NewList.push_back(40);
	NewList.push_back(50);

	GameEngineList<int>::iterator iter = NewList.begin();
	GameEngineList<int>::iterator end = NewList.end();

	GameEngineList<int>::iterator Delete;
	for (; iter != end; ++iter)
	{
		if (*iter == 40)
		{
			Delete = NewList.erase(iter);
		}
	}

	for (iter = NewList.begin(); iter != end; ++iter)
	{
		std::cout << *iter << '\n';
	}
	std::cout << '\n';

	NewList.push_front(0);
	NewList.push_front(-10);
	NewList.push_front(-100);
	NewList.push_front(-1000);

	iter = NewList.begin();
	for (; iter != end; ++iter)
	{
		std::cout << *iter << '\n';
	}
	std::cout << '\n';

	for (iter = NewList.begin(); iter != end; ++iter)
	{
		if (*iter == -100)
		{
			Delete = NewList.erase(iter);
		}
	}

	for (iter = NewList.begin(); iter != end; ++iter)
	{
		std::cout << *iter << '\n';
	}
	std::cout << '\n';

	return 0;
}