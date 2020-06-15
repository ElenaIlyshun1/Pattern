#include<iostream>

using namespace std;

class IMathOper
{
public:
	virtual int Sum(int x, int y) = 0;
	virtual int Divide(int x, int y) = 0;
};

class ConcreteMath :public IMathOper
{
public:
	int Sum(int x, int y)
	{
		return x + y;
	}
	int Divide(int x, int y)
	{
		return x / y;
	}
};
class Proxy :public IMathOper
{
	ConcreteMath*_math;
public:
	Proxy()
	{
		_math = new ConcreteMath();
	}
	int Sum(int x, int y)
	{
		if (x > 0 && y > 0)
			return _math->Sum(x, y);
		else
		{
			cout << "\nuncorrect operation\n";
			return 0;
		}
	}
	int Divide(int x, int y)
	{
		if (y != 0)
			return _math->Divide(x, y);
		else
		{
			cout << "\nuncorrect operation\n";
			return 0;
		}
	}
};/*
  void main()
  {
  IMathOper*oper = new Proxy();
  cout<<oper->Sum(5, 3);
  cout<<oper->Divide(5, 0);
  }*/