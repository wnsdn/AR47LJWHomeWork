#pragma once

#include "Struct.h"

class Object
{
public:
	virtual void Update();
	virtual void Render();

	const Point& GetPoint() const
	{
		return Pt;
	}
	void SetPoint(const Point& _Pt)
	{
		Pt = _Pt;
	}

	wchar_t GetRenderChar() const
	{
		return RenderChar;
	}
	void SetRenderChar(const wchar_t _RenderChar)
	{
		RenderChar = _RenderChar;
	}

	bool GetActive() const
	{
		return Active;
	}
	void SetActive(const bool _Active)
	{
		Active = _Active;
	}
	
	Object()
		: Pt()
		, RenderChar(' ')
		, Active(true)
	{}
	virtual ~Object() {}

	Object(const Object& _ref) = delete;
	Object(Object&& _ref) noexcept = delete;
	Object& operator=(const Object& _ref) = delete;
	Object& operator=(Object&& _ref) noexcept = delete;
private:
	Point Pt;
	wchar_t RenderChar;
	bool Active;
};
