#include "CompositeUnit.h"
#include<iostream>



CompositeUnit::CompositeUnit()
{
}


CompositeUnit::~CompositeUnit()
{
	for (int i = 0; i<fleet.size(); ++i)
		delete fleet[i];
}

int CompositeUnit::GetPower() const
{
	std::cout << "\n---breanch---\n";
	int amount = 0;
	for (int i = 0; i < fleet.size(); i++) {
		amount += fleet[i]->GetPower();
	}
	return amount;
}

void CompositeUnit::AddUnit(Unit* p)
{
	fleet.push_back(p);
}

