#pragma once
#include <iostream>
using namespace std;

class BlueRectangle: public PaintApi // concrete implementor B, конкретна реалізація B
{

public:

	BlueRectangle()
	{
	}

	virtual ~BlueRectangle()
	{
	}
public:
	virtual void DrawRectangle(int x, int y, int endx, int endy)
	{
		cout << "Draw Blue Rectangle\n x = " << x << " y = " << y << " endx = " << endx << " endy = " << endy << endl;
	}
};

