#include "Item.h"

#include <StaticLib/ConsoleGameScreen.h>
#include <StaticLib/Random.h>

void Item::Update()
{
	Object::Update();
}

Item::Item()
{
	Set_RenderChar('i');
	int x = Random::RandomInt(0, ConsoleGameScreen::Get_MainScreen().Get_Size().x - 1);
	int y = Random::RandomInt(0, ConsoleGameScreen::Get_MainScreen().Get_Size().y - 1);
	Set_Pt({ x, y });
}
