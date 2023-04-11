#include "ConsoleGameObject.h"

#include "ConsoleGameScreen.h"

void ConsoleGameObject::Update()
{
}

void ConsoleGameObject::Render()
{
	if (false == GetUpdate())
	{
		return;
	}

	ConsoleGameScreen::GetMainScreen().SetScreenCharacter(m_Pos, m_RenderChar);
}

ConsoleGameObject::ConsoleGameObject()
	: m_Pos()
	, m_RenderChar(' ')
	, m_bUpdate(true)
	, m_bDeath(false)
{
}

ConsoleGameObject::~ConsoleGameObject()
{
}
