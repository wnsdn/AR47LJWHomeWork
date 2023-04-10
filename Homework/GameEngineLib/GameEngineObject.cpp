#include "GameEngineObject.h"

#include "GameEngineScreen.h"

void GameEngineObject::Update()
{
}

void GameEngineObject::Render()
{
	if (false == GetUpdate())
	{
		return;
	}

	GameEngineScreen::GetMainScreen().SetScreenCharacter(m_Pos, m_RenderChar);
}

GameEngineObject::GameEngineObject()
	: m_Pos()
	, m_RenderChar(' ')
	, m_bUpdate(true)
	, m_bDeath(false)
{
}

GameEngineObject::~GameEngineObject()
{
}
