#include "Random.h"

#include <iostream>

void Random::Init()
{
	srand((int)time(nullptr));
}

const Point Random::RandomPoint(const Point& _Max, const Point& _Min)
{
	Point TempPoint;
	TempPoint.x = (rand() % (_Max.x - _Min.x + 1)) + _Min.x;
	TempPoint.y = (rand() % (_Max.y - _Min.y + 1)) + _Min.y;

	return TempPoint;
}

Random::Random()
	: Seed(0)
{
}

Random::~Random()
{
}
