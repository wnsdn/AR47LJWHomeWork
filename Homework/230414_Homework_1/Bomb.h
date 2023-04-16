#pragma once

#include <StaticLib/Object.h>

class Bomb : public Object
{
public:
	void Update() override;

	static int Get_MaxPower()
	{
		return m_MaxPower;
	}
	static void Set_MaxPower(const int _MaxPower)
	{
		m_MaxPower = _MaxPower;
	}

	Bomb()
		: m_Count(8)
		, m_CurPower(0)
	{
		Set_RenderChar('@');
	}
	~Bomb();

	Bomb(const Bomb& _ref) = delete;
	Bomb(Bomb&& _ref) noexcept = delete;
	Bomb& operator=(const Bomb& _ref) = delete;
	Bomb& operator=(Bomb&& _ref) noexcept = delete;
private:
	int m_Count;
	int m_CurPower;
	static int m_MaxPower;
};
