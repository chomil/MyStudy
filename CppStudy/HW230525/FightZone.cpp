#include <iostream>
#include <conio.h>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"



void FightZone::Fight(Player& NewPlayer, Monster& NewMonster)

{
	while (true)
	{
		system("cls");

		// 한번에 함수로 만든것이고
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		_getch();

		system("cls");
		NewMonster.Damage(NewPlayer.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewMonster.DamagePrint(NewPlayer.GetName(), NewPlayer.GetAtt());
		_getch();

		if (true == NewMonster.IsDeath())
		{
			printf_s("%s가 죽었습니다.\n", NewMonster.GetName());
			printf_s("%s의 승리입니다.\n", NewPlayer.GetName());
			_getch();
			return;
		}

		system("cls");
		NewPlayer.Damage(NewMonster.GetAtt());
		NewPlayer.StatusRender();
		NewMonster.StatusRender();
		NewMonster.DamagePrint(NewPlayer.GetName(), NewPlayer.GetAtt());
		NewPlayer.DamagePrint(NewMonster.GetName(), NewMonster.GetAtt());
		_getch();

		if (true == NewPlayer.IsDeath())
		{
			printf_s("%s가 죽었습니다.\n", NewPlayer.GetName());
			printf_s("%s의 승리입니다.\n", NewMonster.GetName());
			_getch();
			return;
		}
	}
}