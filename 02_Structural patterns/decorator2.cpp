#include<iostream>
#include<string>

using namespace std;

class IPersonDescribtion
{
public:
	string _descr;
	virtual string GetDescr() = 0;
	virtual void SetDescr() = 0;
};

class PersonDescr : public IPersonDescribtion
{
public:
	PersonDescr()
	{
		SetDescr();
	}
	string GetDescr()
	{
		return _descr;
	};
	void SetDescr()
	{
		_descr = "I weared in ...";
	}
};

class Decorator :public IPersonDescribtion
{
public:
	Decorator()
	{

	}
	IPersonDescribtion*_persDescr;
	Decorator(IPersonDescribtion*persDescr)
	{
		_persDescr = persDescr;
	}
};

class PutOnSuit :public Decorator
{
public:
	PutOnSuit()
	{

	}
	PutOnSuit(IPersonDescribtion*persDescr) :Decorator(persDescr)
	{
		if (persDescr == nullptr)
		{
			cout << "nobody hear...\n";
		}
		else
			SetDescr();
	}
	string GetDescr()
	{
		return _persDescr->_descr;
	};
	void SetDescr()
	{
		_persDescr->_descr += " suit";
	}
};
class PutOnCoat :public Decorator
{
public:
	PutOnCoat()
	{

	}
	PutOnCoat(IPersonDescribtion*persDescr) :Decorator(persDescr)
	{
		if (persDescr == nullptr)
		{
			cout << "nobody hear...\n";
		}
		else
			SetDescr();
	}
	string GetDescr()
	{
		return _persDescr->_descr;
	};
	void SetDescr()
	{
		_persDescr->_descr += " coat";
	}
};
void main()
{
	IPersonDescribtion*pers = new PersonDescr();
	Decorator*decor = new PutOnSuit(pers);
	cout << pers->GetDescr();
	cout << endl;

	IPersonDescribtion*pers1 = new PersonDescr();
	Decorator*decor1 = new PutOnSuit(pers1);
	delete decor1;
	decor1 = new PutOnCoat(pers1);
	cout << pers1->GetDescr();
}