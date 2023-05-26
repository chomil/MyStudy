#pragma once

#include "ConstVal.h"

class Unit
{
public:
	Unit()
		:Pos()
	{
	}
public:
	int4 GetPos() const
	{
		return Pos;
	}

	void AddPos(const int4& _Pos)
	{
		Pos += _Pos;
	}

	void SetPos(const int4& _Pos)
	{
		Pos = _Pos;
	}

public:
	int4 Pos;
};

