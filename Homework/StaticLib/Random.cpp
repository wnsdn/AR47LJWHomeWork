#include "Random.h"

#include <iostream>

void Random::Init()
{
	srand((int)time(nullptr));
}

int Random::RandomInt(int _Min, int _Max)
{
	return (rand() % (_Max - _Min + 1)) + _Min;
}

Random::Random()
{
}

Random::~Random()
{
}
