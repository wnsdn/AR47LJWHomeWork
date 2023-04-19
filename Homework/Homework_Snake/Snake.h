#pragma once

#include <vector>
#include <tuple>

#include <StaticLibrary/Object.h>

using std::vector;

class Snake : public Object
{
public:
	static bool IsGameUpdate;
	static bool Win;

	void Update() override;
	void Render() override;

	Snake();
	~Snake() {}

	Snake(const Snake& _ref) = delete;
	Snake(Snake&& _ref) noexcept = delete;
	Snake& operator=(const Snake& _ref) = delete;
	Snake& operator=(Snake&& _ref) noexcept = delete;
private:
	int Direction;
	vector<std::tuple<Point, Point, int, int>> Body;
	const wchar_t HeadChar[5] = L"¡ã¡å¢¸¢º";
	const wchar_t BodyChar[5] = L"¡â¡ä¢·¢¹";
};
