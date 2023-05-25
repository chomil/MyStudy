#pragma once

class Player
{
public:
	void StatusRender();
	void DamagePrint(const char* const _AttName, int _Att);
	void Damage(int _Att);
	bool IsDeath();

public:
	const char* GetName()
	{
		return Name;
	}
	int GetAtt()
	{
		return Att;
	}

private:
	char Name[40] = "Player";
	int Att = 10;
	int Hp = 100;
};