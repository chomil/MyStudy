#include <iostream>

class Test
{
public:
    int A;
    __int64 B;
    char C;
    char D;
    short E; // 2바이트 정수
    int F;
};
// [A][A][A][A][][][][] [B][B][B][B][B][B][B][B] [C][D][E][E][F][F][F][F]


class Player
{
public:
    int HP;
    int ATT;
};

//  [H][H][H][H][A][A][A][A] //  [T][T][T][T][][][][]
void TestFunction(Player _Newplayer, int _Test)
{
    __int64 Address0 = (__int64)&_Newplayer.HP;
    __int64 Address1 = (__int64)&_Newplayer.ATT;
    __int64 Address2 = (__int64)&_Test;
}

int main()
{
    size_t Size = sizeof(Test);

    Test NewTest;

    __int64 Address0 = (__int64)&NewTest.A;
    __int64 Address1 = (__int64)&NewTest.B;
    __int64 Address2 = (__int64)&NewTest.C;
    __int64 Address3 = (__int64)&NewTest.D;
    __int64 Address4 = (__int64)&NewTest.E;
    __int64 Address5 = (__int64)&NewTest.F;

    Player NewPlayer=Player();
    TestFunction(NewPlayer, 20);
}