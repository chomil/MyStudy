#pragma once
#include <iostream>
#include "ConstVal.h"

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

    void Clear();
    bool IsScreenOut(const int4& _Pos) const;
    void Print() const;

private:
    char BaseCh = ' ';
    char ArrScreen[YLine][XLine + 1] = {};
};