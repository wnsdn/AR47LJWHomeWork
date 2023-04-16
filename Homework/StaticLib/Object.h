#pragma once

#include "Struct.h"

class Object
{
public:
	virtual void Update();

	const Point& Get_Pt() const
	{
		return m_Pt;
	}
	void Set_Pt(const Point& _Pt)
	{
		m_Pt = _Pt;
	}

	char Get_RenderChar() const
	{
		return m_RenderChar;
	}
	void Set_RenderChar(const char _RenderChar)
	{
		m_RenderChar = _RenderChar;
	}

	bool Get_Active() const
	{
		return m_Active;
	}
	void Set_Active(const bool _Active)
	{
		m_Active = _Active;
	}
	
	Object()
		: m_Pt()
		, m_RenderChar(' ')
		, m_Active(true)
	{}
	~Object()
	{}

	Object(const Object& _ref) = delete;
	Object(Object&& _ref) noexcept = delete;
	Object& operator=(const Object& _ref) = delete;
	Object& operator=(Object&& _ref) noexcept = delete;
private:
	Point m_Pt;
	char m_RenderChar;
	bool m_Active;
};
