#include "Object.h"

#include "ConsoleGameScreen.h"

void Object::Update()
{

}

void Object::Render()
{
	if (ConsoleGameScreen::GetMainScreen().IsOutOfScreen(Pt))
	{
		return;
	}

	ConsoleGameScreen::GetMainScreen().SetScreenChar(Pt, RenderChar);
}

void Object::Delete()
{

}
