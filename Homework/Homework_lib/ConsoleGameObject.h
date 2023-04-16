#pragma once

#include "ConsoleGameMath.h"

class ConsoleGameObject
{
public:
	virtual void Update();
	virtual void Render();

	void SetPos(const int2& _ref)
	{
		m_Pos = _ref;
	}
	int2 GetPos() const
	{
		return m_Pos;
	}

	void SetRenderChar(const char _ch)
	{
		m_RenderChar = _ch;
	}
	char GetRenderChar() const
	{
		return m_RenderChar;
	}

	void SetUpdate(const bool _update)
	{
		m_bUpdate = _update;
	}
	bool GetUpdate() const
	{
		return m_bUpdate;
	}

	void SetDeath(const bool _death)
	{
		m_bDeath = _death;
	}
	bool GetDeath() const
	{
		return m_bDeath;
	}

	ConsoleGameObject();
	~ConsoleGameObject();

	ConsoleGameObject(const ConsoleGameObject& _ref) = delete;
	ConsoleGameObject(ConsoleGameObject&& _ref) noexcept = delete;
	ConsoleGameObject& operator=(const ConsoleGameObject& _ref) = delete;
	ConsoleGameObject& operator=(ConsoleGameObject&& _ref) noexcept = delete;
protected:

private:
	int2 m_Pos;
	char m_RenderChar;
	bool m_bUpdate;
	bool m_bDeath;
};

