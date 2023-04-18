#include "Bullet.h"

Bullet::Bullet()
{
}

void Bullet::Move()
{
	if (Pos.y >= 0 && IsMove)
	{
		Pos.y -= 1;
	}
}