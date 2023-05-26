#pragma once
#include "DataTypes.h"

class ConsoleScreen;
class Player;
class Wall;
class Bullet;

class GameManager
{
public:
	void GamePlay();
	bool IsPlayerCollision(int4 _Direction);
	void BulletHit();
	void Input();

private:
	ConsoleScreen* Screen;
	Player* MainPlayer;
	Wall* Walls[10];
	Bullet* PlayerBullet;
};

