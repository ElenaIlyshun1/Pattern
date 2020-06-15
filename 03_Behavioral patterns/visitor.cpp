#include<iostream>
#include<list>

using namespace std;
class Visitor;

class House
{
public:
	virtual void accept(class Visitor*v) = 0;
};

class GirlHouse : public House
{
public:

	void accept(Visitor*v);
	void GiftDress()
	{
		cout << "such abuitiful dress\n";
	}
};
class BoyHouse : public House
{
public:

	void accept(Visitor*v);
	void GiftCar()
	{
		cout << "such a cool car\n";
	}
};

class Visitor
{
	public:
		void visitGirlHouse(GirlHouse*g)
		{
			g->GiftDress();
	}
		void visitBoyHouse(BoyHouse*b)
		{
			b->GiftCar();
		}
};

class Village
{
public:
	list<House*>houses;

	void Add(House*h)
	{
		houses.push_back(h);
	}
	void Accept(Visitor*v)
	{
		for (auto el : houses)
		{
			el->accept(v);
		}
	}
};
void GirlHouse::accept(Visitor*v)
{
	v->visitGirlHouse(this);
}
void BoyHouse::accept(Visitor*v)
{
	v->visitBoyHouse(this);
}

void main()
{
	Village*v = new Village();
	Visitor*santa = new Visitor();
	v->Add(new GirlHouse);
	v->Add(new GirlHouse);
	v->Add(new GirlHouse);
	v->Add(new BoyHouse);
	v->Accept(santa);
}