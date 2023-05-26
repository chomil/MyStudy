#pragma once
#include "Unit.h"

class Bullet : public Unit
{
public:
	bool GetShoot()
	{
		return bShoot;
	}
	void SetShoot(bool _bShoot)
	{
		bShoot = _bShoot;
	}


	int4& GetMoveDir()
	{
		return MoveDir;
	}	
	void SetMoveDir(const int4& _Dir)
	{
		MoveDir = _Dir;
	}
private:
	int4 MoveDir = Up;
	bool bShoot = false;
};

