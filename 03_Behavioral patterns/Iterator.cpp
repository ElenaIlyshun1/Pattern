#include<iostream>

using namespace std;
class Iterator;
class Collection
{
//friend class Iterator;
private:
	enum { maxSize = 10 };
	int arr[maxSize];
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
	bool Push(int a)
	{
		if (curSize < maxSize)
		{
			arr[curSize] = a;
			curSize++;
			return true;
		}
		return false;
	}
	bool Pop(int &a)
	{
		if (isEmpty())
			return false;
		curSize--;
		return arr[curSize];
	}
	bool isEmpty()
	{
		return curSize == 0;
	}
	int operator[](int index)
	{
		if(index<curSize)
		return arr[index];
		return 0;
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
		return _collection->GetCurSize()-1;
	}
	int NextItem()
	{
		ind++;
		return _collection->arr[ind];
	}
	int CurItem()
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

bool operator ==(Collection&l, Collection&r)
{
	Iterator*itL = l.iterator();
	Iterator*itR = r.iterator();
	if (itL->End() != itR->End())return false;
	for (int i = 0; i < itL->End();i++)
	{
		if (itL->HasNext() ^ itR->HasNext())
			return false;
		if (itL->HasNext() && itR->HasNext())
		{
			if (itL->CurItem() != itR->CurItem())
			{
				return false;
			}
			itL->NextItem();
			itR->NextItem();
		}
		
	}
	return true;
}
void main()
{
	Collection myCol;
	myCol.Push(5);
	myCol.Push(3);
	myCol.Push(1);
	//myCol.Push(3);
	Collection myCol1;
	myCol1.Push(5);
	myCol1.Push(3);
	myCol1.Push(1);
	myCol1.Push(3);

	Iterator*it = myCol.iterator();
	int i = it->First();
	int end = it->End();
	while (i<end)
	{
		cout << it->CurItem()<<" ";
		it->NextItem();
		i++;
	}
	cout << myCol[2];
	cout << (myCol == myCol1);
}