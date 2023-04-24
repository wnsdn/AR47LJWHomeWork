#include <iostream>
#include <crtdbg.h>

#include "Map.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Map<int, int> _map;

	_map.insert(Pair<int, int>(20, 1));
	_map.insert(Pair<int, int>(8, 1));
	_map.insert(Pair<int, int>(32, 1));

	Map<int, int>::iterator begin = _map.begin();
	Map<int, int>::iterator end = _map.end();
	Map<int, int>::iterator iter;

	for (iter = begin; iter != end; ++iter)
	{
		std::cout << iter->first << ' ';
	}
	putchar('\n');

	_map.insert(Pair<int, int>(17, 1));
	_map.insert(Pair<int, int>(42, 1));

	for (iter = begin; iter != end; ++iter)
	{
		std::cout << iter->first << ' ';
	}
	putchar('\n');

	_map.insert(Pair<int, int>(10, rand()));
	_map.insert(Pair<int, int>(7, rand()));
	_map.insert(Pair<int, int>(15, rand()));
	_map.insert(Pair<int, int>(25, rand()));
	_map.insert(Pair<int, int>(17, rand()));
	_map.insert(Pair<int, int>(18, rand()));
	_map.insert(Pair<int, int>(2, rand()));

	_map.erase(_map.find(17));
	_map.erase(_map.find(32));
	_map.erase(_map.find(4));

	_map.insert(Pair<int, int>(6, rand()));
	_map.insert(Pair<int, int>(5, rand()));
	_map.insert(Pair<int, int>(4, rand()));
	_map.insert(Pair<int, int>(9, rand()));
	_map.insert(Pair<int, int>(8, rand()));
	_map.insert(Pair<int, int>(1, rand()));

	for (iter = begin; iter != end; ++iter)
	{
		std::cout << iter->first << ' ';
	}
	putchar('\n');

	return 0;
}