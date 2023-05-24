#include <iostream>
#include <conio.h>

// 숙제 플레이어가 화면 바깥으로 나가지 못하게 

const int XLine = 20;
const int YLine = 10;


// 이녀석은 캡슐화된 클래스라기 보다는 기본자료형
class int4
{
public:
    int X = 0;
    int Y = 0;
    int Z = 0;
    int W = 1;

    void operator=(const int4& _Other)
    {
        X = _Other.X;
        Y = _Other.Y;
        Z = _Other.Z;
        W = _Other.W;
    }

    void operator+=(const int4& _Other)
    {
        X += _Other.X;
        Y += _Other.Y;
        Z += _Other.Z;
        W += _Other.W;
    }

};

// 리스트 이니셜라이저
const int4 Left = { -1, 0 };
const int4 Right = { 1, 0 };
const int4 Up = { 0, -1 };
const int4 Down = { 0, 1 };


class ConsoleScreen
{
public:
    ConsoleScreen()
    {

    }

    void Init(char _BaseCh)
    {
        BaseCh = _BaseCh;
        Clear();
    }

    void SetPixel(const int4& _Pos, char _Ch)
    {
        ArrScreen[_Pos.Y][_Pos.X] = _Ch;
    }

    void Clear()
    {
        system("cls");
        for (size_t y = 0; y < YLine; y++)
        {
            for (size_t x = 0; x < XLine; x++)
            {
                ArrScreen[y][x] = BaseCh;
            }
            ArrScreen[y][XLine] = 0;
        }
    }


    void Print()
    {
        for (size_t y = 0; y < YLine; y++)
        {
            printf_s(ArrScreen[y]);
            printf_s("\n");
        }
    }

protected:


private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};

class Player
{
public:

    int4 GetPos()
    {
        return Pos;
    }

    void AddPos(const int4& _Pos)
    {
        Pos += _Pos;
        
        //화면 밖으로 안나가게
        if (Pos.X < 0)
        {
            Pos.X = 0;
        }
        else if (Pos.X >= XLine)
        {
            Pos.X = XLine - 1;
        }

        if (Pos.Y < 0)
        {
            Pos.Y = 0;
        }
        else if (Pos.Y >= YLine)
        {
            Pos.Y = YLine - 1;
        }
    }


    void SetPos(const int4& _Pos)
    {
        Pos = _Pos;
    }

    Player()
        : Pos()
    {
    }

    Player(const Player&) = delete;

    void Input()
    {
        char Select = (char)_getch();

        switch (Select)
        {
        case 'a':
            AddPos(Left);
            break;
        case 'd':
            AddPos(Right);
            break;
        case 'w':
            AddPos(Up);
            break;
        case 's':
            AddPos(Down);
            break;
        default:
            break;
        }
    }

protected:

private:



    int4 Pos;
};

int main()
{
    ConsoleScreen Screen;
    Screen.Init('*');

    Player MainPlayer;
    // 클래스의경우에는 
    MainPlayer.SetPos({ 10, 5 });

    while (true)
    {
        Screen.Clear();
        Screen.SetPixel(MainPlayer.GetPos(), 'a');
        Screen.Print();

        MainPlayer.Input();
    }


}
