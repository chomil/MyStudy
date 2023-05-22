#include <iostream>
#include <conio.h>

// 숙제 1 -- 문자의 오른쪽끝 맞추기. 이름은 알파벳만

// 숙제 2 -- 실시간으로 데미지 메세지가 나오는순간 체력이 곧바로 감소되게 

// 숙제 3 -- 누군가의 Hp가 0이 된순간 종료


int StrLen(const char* const _Str)
{
    if (_Str == nullptr)
    {
        return -1;
    }
    int i = 0;
    while (_Str[i] != 0)
    {
        i++;
    }
    return i;
}

void StatusRender(const char* const _Name, int _Att, int _Hp)
{
    // 길이 40
    int iNameLen = StrLen(_Name);

    printf_s("%s", _Name);
    for (int i = 0; i < 40 - iNameLen; i++)
    {
        printf_s("-");
    }
    printf_s("\n");
    printf_s("공격력 : %d\n", _Att);
    printf_s("체  력 : %d\n", _Hp);    
    for (int i = 0; i < 40; i++)
    {
        printf_s("-");
    }
    printf_s("\n\n");
}

void DamagePrint(const char* const _AttName, const char* const _DefName, int _Att)
{
    printf_s("%s가 %s를 공격했습니다.\n", _AttName, _DefName);
    printf_s("%s는 %d의 데미지를 입었습니다.\n\n", _DefName, _Att);
}

void Damage(int& _Hp, int _Att)
{
    _Hp -= _Att;
    if (_Hp < 0)
    {
        _Hp = 0;
    }
}


int main()
{
    int PlayerHp = 200;
    int PlayerAtt = 40;
    char PlayerName[40] = "Player123123";

    int MonsterHp = 100;
    int MonsterAtt = 20;
    char MonsterName[40] = "Monster";

    while (true)
    {
        system("cls");
        //상태창출력
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);

        _getch();

        system("cls");
        //상태창출력
        Damage(MonsterHp, PlayerAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        if (MonsterHp <= 0)
        {
            printf_s("%s가 죽었습니다.\n\n", MonsterName);
            return 0;
        }

        _getch();

        system("cls");
        //상태창출력
        Damage(PlayerHp, MonsterAtt);
        StatusRender(PlayerName, PlayerAtt, PlayerHp);
        StatusRender(MonsterName, MonsterAtt, MonsterHp);
        DamagePrint(PlayerName, MonsterName, PlayerAtt);
        DamagePrint(MonsterName, PlayerName, MonsterAtt);
        if (PlayerHp <= 0)
        {
            printf_s("%s가 죽었습니다.\n\n", PlayerName);
            return 0;
        }


        _getch();
    }
}
