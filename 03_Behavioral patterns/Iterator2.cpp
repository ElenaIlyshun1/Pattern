#include<iostream>
#include<string>
using namespace std;
class Unit
{
	int power;
	string _name;
public:
	Unit()
	{
		power = 10;
	}
	void SetName(string name)
	{
		_name = name;
	}
	int GetPower()
	{
		return power;
	}
	string GetName()
	{
		return _name;
	}
	friend ostream& operator <<(ostream&out, Unit& a);

};
class Iterator;
class Collection
{
	friend class Iterator;
private:
	enum { maxSize = 10 };
	Unit arr[maxSize];
	int curSize;
public:
	Collection()
	{
		curSize = 0;
	}
	int GetCurSize()
	{
		return curSize;
	}
	int GetMaxSize()
	{
		return maxSize;
	}
	bool Push(string name)
	{
		if (curSize < maxSize)
		{
			arr[curSize].SetName(name);
			curSize++;
			return true;
		}
		return false;
	}
	bool Pop(Unit &a)
	{
		if (isEmpty())
			return false;
		curSize--;
		arr[curSize] = a;
		return true;
	}
	bool isEmpty()
	{
		return curSize == 0;
	}
	Unit operator[](int index)
	{
		if (index<curSize)
			return arr[index];
		return arr[0];
	}
	Iterator*iterator();
};

class Iterator
{
	Collection*_collection;
	int ind;
public:
	Iterator(Collection*collection)
	{
		_collection = collection;
		ind = 0;
	}
	int First()
	{
		return 0;
	}
	int End()
	{
		return _collection->GetCurSize() - 1;
	}
	Unit NextItem()
	{
		ind++;
		return _collection->arr[ind];
	}
	Unit CurItem()
	{
		return _collection->arr[ind];
	}
	bool IsFull()
	{
		return _collection->GetCurSize() == _collection->GetMaxSize() - 1;
	}
	bool HasNext()
	{
		return ind < End();
	}
	
};
Iterator*Collection::iterator()
{
	return new Iterator(this);
}

ostream& operator <<(ostream&out, Unit& a)
{
	cout << to_string(a.GetPower()) + a.GetName() << endl;
	return out;
}

bool operator ==(Collection&l, Collection&r)
{
	return true;
}
void main()
{
	Collection myCol;
	myCol.Push("unit 1");
	myCol.Push("unit 2");
	myCol.Push("unit 3");
	//myCol.Push(3);
	Collection myCol1;
	myCol1.Push("unit 1");
	myCol1.Push("unit 2");
	myCol1.Push("unit 3");
	myCol1.Push("unit 4");
	Iterator*it = myCol.iterator();
	int i = it->First();
	int end = it->End();
	while (i<end)
	{
		cout <<(it->CurItem()) << " ";
		it->NextItem();
		i++;
	}
	cout << myCol[2];
	it = myCol1.iterator();
}