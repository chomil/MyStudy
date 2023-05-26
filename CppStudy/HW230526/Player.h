#pragma once

#include <iostream>
#include <conio.h>
#include "Unit.h"



class ConsoleScreen;
class Player : public Unit
{
public:
	Player()
	{
	}

	Player(const Player&) = delete;

	void SetLastMoveDir(const int4& _Dir)
	{
		LastMoveDir = _Dir;
	}

	int4& GetLastMoveDir()
	{
		return LastMoveDir;
	}

private:
	int4 LastMoveDir = Up;
};