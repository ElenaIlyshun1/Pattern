#pragma once
#include "Unit.h"
class MonoTubeShip :
	public Unit
{
public:

	MonoTubeShip()
	{
	}

	virtual ~MonoTubeShip()
	{
	}
public:
	int GetPower() const
	{
		cout << "1 ";
		return 1;
	}
	void AddUnit(Unit* p)
	{
		throw "This operation is not supported!";
	}

};

