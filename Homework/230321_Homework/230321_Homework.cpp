﻿#include <iostream>
#include <conio.h>

int PlayerHp = 100;
int PlayerAtt = 10;

int MonsterHp = 100;
int MonsterAtt = 10;

void StatusRender(const char* const _Name, const int& _Att, const int& _Hp)
{
    printf_s("%s 의 스테이터스 ------------\n", _Name);
    printf_s("공격력 : %d\n", _Att);
    printf_s("체력 : %d\n", _Hp);
    printf_s("---------------------------\n");
}

void Damage(const char* const _AttName, const char* const _DefName, const int& _Att, int& _Hp)
{
    _Hp -= _Att;
    StatusRender("Player", PlayerAtt, PlayerHp);
    StatusRender("Monster", MonsterAtt, MonsterHp);

    printf_s("%s가 공격을 시작합니다\n", _AttName);
    printf_s("%s가 %d의 데미지를 입었습니다.\n", _DefName, _Att);
}

int main()
{

    while (true)
    {
        system("cls");
        StatusRender("Player", PlayerAtt, PlayerHp);
        StatusRender("Monster", MonsterAtt, MonsterHp);
        _getch();

        system("cls");
        Damage("Player", "Monster", PlayerAtt, MonsterHp);
        _getch();

        if (0 >= MonsterHp)
        {
            printf_s("몬스터가 죽었습니다.");
            printf_s("플레이어의 승리입니다.");
            _getch();
            break;
        }

        system("cls");
        Damage("Monster", "Player", MonsterAtt, PlayerHp);
        _getch();

        if (0 >= PlayerHp)
        {
            printf_s("플레이어가 죽었습니다.");
            printf_s("몬스터의 승리입니다.");
            _getch();
            break;
        }
    }
}
