#include "Item.h"

#include <StaticLibrary/ConsoleGameScreen.h>
#include <StaticLibrary/Random.h>

void Item::Update()
{
	Object::Update();
}

Item::Item()
{
	SetRenderChar('&');
	int x = Random::RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().x - 1);
	int y = Random::RandomInt(0, ConsoleGameScreen::GetMainScreen().GetScreenSize().y - 1);
	SetPoint({ x, y });
}
