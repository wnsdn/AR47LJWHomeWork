#pragma once

#include <StaticLibrary/Object.h>

class Bomb : public Object
{
public:
	void Update() override;

	static int GetPower()
	{
		return m_Power;
	}
	static void SetPower(const int _Power)
	{
		m_Power = _Power;
	}

	Bomb()
		: m_Count(8)
		, m_CurPower(0)
		, m_MaxPower(m_Power)
	{
		SetRenderChar('@');
	}
	~Bomb();

	Bomb(const Bomb& _ref) = delete;
	Bomb(Bomb&& _ref) noexcept = delete;
	Bomb& operator=(const Bomb& _ref) = delete;
	Bomb& operator=(Bomb&& _ref) noexcept = delete;
private:
	int m_Count;
	int m_CurPower;
	int m_MaxPower;

	static int m_Power;
};
