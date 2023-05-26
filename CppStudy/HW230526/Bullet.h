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
private:
	bool bShoot = false;
};

