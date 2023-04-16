#include "Random.h"

#include <iostream>

int Random::RandomInt(int _Min, int _Max)
{
	return (rand() % (_Max - _Min + 1)) + _Min;
}

Random::Random()
{
	m_Seed = (int)time(nullptr);
	srand(m_Seed);
}

Random::~Random()
{
}
