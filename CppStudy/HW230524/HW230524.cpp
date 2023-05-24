#include <iostream>
#include <conio.h>

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

const int iLineLen = 40;

class Player
{

public:
    void StatusRender()
    {
        int iNameLen = StrLen(szName);

        printf_s("%s", szName);
        for (int i = 0; i < iLineLen - iNameLen; i++)
        {
            printf_s("-");
        }
        printf_s("\n");
        printf_s("공격력 : %d\n", iAtt);
        printf_s("체  력 : %d\n", iHp);
        for (int i = 0; i < iLineLen; i++)
        {
            printf_s("-");
        }
        printf_s("\n\n");
    }
    void DamagePrint(const char* const _szAttName, int _iAtt)
    {
        printf_s("%s가 %s를 공격했습니다.\n", _szAttName, szName);
        printf_s("%s는 %d의 데미지를 입었습니다.\n\n", szName, _iAtt);
    }
    void Damage(int _iAtt)
    {
        iHp -= _iAtt;
        if (iHp < 0)
        {
            iHp = 0;
        }
    }

    bool IsDead()
    {
        if (iHp <= 0)
        {
            return true;
        }

        return false;
    }

public:    

    const char* const GetName()
    {
        return szName;
    }
    int GetHP()
    {
        return iHp;
    }
    void SetHP(int _iHp)
    {
        iHp = _iHp;
    }
    int GetAtt()
    {
        return iAtt;
    }
private:
    char szName[40] = "Player";
    int iHp = 100;
    int iAtt = 20;
};

class Monster
{

public:
    void StatusRender()
    {
        int iNameLen = StrLen(szName);

        printf_s("%s", szName);
        for (int i = 0; i < iLineLen - iNameLen; i++)
        {
            printf_s("-");
        }
        printf_s("\n");
        printf_s("공격력 : %d\n", iAtt);
        printf_s("체  력 : %d\n", iHp);
        for (int i = 0; i < iLineLen; i++)
        {
            printf_s("-");
        }
        printf_s("\n\n");
    }
    void DamagePrint(const char* const _szAttName, int _iAtt)
    {
        printf_s("%s가 %s를 공격했습니다.\n", _szAttName, szName);
        printf_s("%s는 %d의 데미지를 입었습니다.\n\n", szName, _iAtt);
    }
    void Damage(int _iAtt)
    {
        iHp -= _iAtt;
        if (iHp < 0)
        {
            iHp = 0;
        }
    }

    bool IsDead()
    {
        if (iHp <= 0)
        {
            return true;
        }

        return false;
    }

public:
    const char* const GetName()
    {
        return szName;
    }
    int GetHP()
    {
        return iHp;
    }
    void SetHP(int _iHp)
    {
        iHp = _iHp;
    }
    int GetAtt()
    {
        return iAtt;
    }
private:
    char szName[40] = "Monster";
    int iHp = 50;
    int iAtt = 10;
};

int main()
{
    Player player;
    Monster monster;


    while (true)
    {
        system("cls");
        //상태창출력
        player.StatusRender();
        monster.StatusRender();
        _getch();

        system("cls");
        //상태창출력
        monster.Damage(player.GetAtt());
        player.StatusRender();
        monster.StatusRender();
        monster.DamagePrint(player.GetName(), player.GetAtt());
        if (monster.IsDead())
        {
            printf_s("%s가 죽었습니다.\n", monster.GetName());
            printf_s("%s의 승리입니다.\n\n", player.GetName());
            return 0;
        }

        _getch();

        system("cls");
        //상태창출력
        player.Damage(monster.GetAtt());
        player.StatusRender();
        monster.StatusRender();
        monster.DamagePrint(player.GetName(), player.GetAtt());
        player.DamagePrint(monster.GetName(), monster.GetAtt());
        if (player.IsDead())
        {
            printf_s("%s가 죽었습니다.\n", player.GetName());
            printf_s("%s의 승리입니다.\n\n", monster.GetName());
            return 0;
        }


        _getch();
    }
}
