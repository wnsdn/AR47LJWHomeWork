#pragma once

class Random
{
public:
	static int RandomInt(int _Min, int _Max);

private:
	int m_Seed;

	Random();
	~Random();

	Random(const Random& _ref) = delete;
	Random(Random&& _ref) noexcept = delete;
	Random& operator=(const Random& _ref) = delete;
	Random& operator=(Random&& _ref) noexcept = delete;
};
