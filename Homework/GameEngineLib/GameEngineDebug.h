#pragma once

#include <Windows.h>
#include <assert.h>

#define MessageBoxAssert(Text)\
	MessageBoxA(nullptr, Text, "Error", MB_OK);\
	assert(false);

class GameEngineDebug
{
public:
	static void LeakCheck();

	GameEngineDebug();
	~GameEngineDebug();

	GameEngineDebug(const GameEngineDebug& _ref) = delete;
	GameEngineDebug(GameEngineDebug&& _ref) noexcept = delete;
	GameEngineDebug& operator=(const GameEngineDebug& _ref) = delete;
	GameEngineDebug& operator=(GameEngineDebug&& _ref) noexcept = delete;
protected:

private:

};

