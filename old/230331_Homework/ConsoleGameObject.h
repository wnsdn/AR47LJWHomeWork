#pragma once
#include "Struct.h"

class ConsoleGameObject
{
public:
	void Render();

	void SetPos(const Point& _pos)
	{
		Pos = _pos;
	}

	Point GetPos() const
	{
		return Pos;
	}

	void SetUpdateValue(bool _update)
	{
		UpdateValue = _update;
	}

	bool GetUpdateValue() const
	{
		return UpdateValue;
	}

	void SetDeathValue(bool _death)
	{
		DeathValue = _death;
	}

	bool GetDeathValue() const
	{
		return DeathValue;
	}

	ConsoleGameObject();
protected:
	Point Pos;
	char RenderChar;
private:
	bool UpdateValue = true;
	bool DeathValue = false;
};

