#include "Head.h"

#include <conio.h>
#include <list>

#include <StaticLib/ConsoleGameScreen.h>
#include <StaticLib/ObjectManager.h>

#include "Enum.h"

bool Head::IsGameUpdate = true;

bool Head::Win = false;
int Head::GameWinCount = 0;

void Head::Update()
{
	Object::Update();

	Parts* tmp = m_Head->next;
	GameWinCount = 1;
	while (tmp)
	{
		ConsoleGameScreen::Get_MainScreen().Set_ScreenChar(tmp->pt, 'O');
		++GameWinCount;
		tmp = tmp->next;
	}

	Point size = ConsoleGameScreen::Get_MainScreen().Get_Size();
	if (GameWinCount == size.x * size.y)
	{
		Win = true;
	}

	if (!_kbhit())
	{
		return;
	}

	m_Head->pt = Get_Pt();
	tmp = m_Head->next;
	while (tmp)
	{
		tmp->PrevPt = tmp->prev->pt;
		tmp = tmp->next;
	}
	Point TailPt = m_Tail->pt;

	switch (_getch())
	{
	case 'w':
	case 'W':
	{
		Set_Pt(Get_Pt() + Point::Dir[(int)Point::Dir::Up]);
		break;
	}
	case 's':
	case 'S':
	{		
		Set_Pt(Get_Pt() + Point::Dir[(int)Point::Dir::Down]);
		break;
	}
	case 'a':
	case 'A':
	{
		Set_Pt(Get_Pt() + Point::Dir[(int)Point::Dir::Left]);
		break;
	}
	case 'd':
	case 'D':
	{
		Set_Pt(Get_Pt() + Point::Dir[(int)Point::Dir::Right]);
		break;
	}
	case 'q':
	case 'Q':
	{
		IsGameUpdate = false;
		break;
	}
	default:
		break;
	}

	tmp = m_Head->next;
	while (tmp)
	{
		if (tmp->pt == Get_Pt())
		{
			IsGameUpdate = false;
			break;
		}

		tmp->pt = tmp->PrevPt;
		tmp = tmp->next;
	}

	if (IsItem(Get_Pt()))
	{
		Parts* NewParts = new Parts;

		m_Tail->next = NewParts;
		NewParts->prev = m_Tail;

		m_Tail = NewParts;

		m_Tail->pt = TailPt;
	}

	if (ConsoleGameScreen::Get_MainScreen().IsOutOfScreen(Get_Pt()))
	{
		IsGameUpdate = false;
	}
}

void Head::Delete()
{
	while (m_Tail)
	{
		Parts* tmp = m_Tail->prev;

		delete m_Tail;
		m_Tail = tmp;
	}
}

Head::Head()
	: m_Head(new Parts)
	, m_Tail(m_Head)
{
	Point ScreenSize = ConsoleGameScreen::Get_MainScreen().Get_Size();

	Set_Pt({ ScreenSize.x / 2, ScreenSize.y / 2 });
	Set_RenderChar('$');
}

Head::~Head()
{
}

bool Head::IsItem(const Point& _pt) const
{
	list<Object*>& Group = ObjectManager::Get_ObjectGroup(ObjectGroup::Item);

	for (auto obj : Group)
	{
		if (obj->Get_Pt() == _pt)
		{
			obj->Set_Active(false);
			return true;
		}
	}

	return false;
}