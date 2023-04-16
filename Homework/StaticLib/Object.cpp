#include "Object.h"

#include "ConsoleGameScreen.h"

void Object::Update()
{
	ConsoleGameScreen::Get_MainScreen().Set_ScreenChar(m_Pt, m_RenderChar);
}
