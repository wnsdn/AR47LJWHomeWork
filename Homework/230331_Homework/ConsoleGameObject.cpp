#include "ConsoleGameObject.h"
#include "ConsoleGameScreen.h"

ConsoleGameObject::ConsoleGameObject()
	: Pos{}, RenderChar{}
{
}

void ConsoleGameObject::Render()
{
	if (!GetUpdateValue())
	{
		return;
	}

	ConsoleGameScreen::Instance().SetCharacter(Pos, RenderChar);
}
