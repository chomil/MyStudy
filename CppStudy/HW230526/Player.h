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

public:
	Player(const Player&) = delete;

};