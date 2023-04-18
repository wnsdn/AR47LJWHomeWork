#pragma once

#include "Struct.h"

class Random
{
public:
	static void Init();
	static const Point RandomPoint(const Point& _Max, const Point& _Min);

private:
	int Seed;

	Random();
	~Random();

	Random(const Random& _ref) = delete;
	Random(Random&& _ref) noexcept = delete;
	Random& operator=(const Random& _ref) = delete;
	Random& operator=(Random&& _ref) noexcept = delete;
};
