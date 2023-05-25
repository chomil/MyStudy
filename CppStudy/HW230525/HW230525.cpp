#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"



int main()
{
	Player NewPlayer;
	Monster NewMonster;
	FightZone FZone;
	FZone.Fight(NewPlayer, NewMonster);
}
