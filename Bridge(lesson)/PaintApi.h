#pragma once
class PaintApi // implementor class
{
public:

	PaintApi()
	{
	}

	virtual ~PaintApi()
	{
	}
public:
	// 	визначає інтерфейс для класів реалізації, цей інтерфейс НЕ зобов'язаний точно відповідати інтерфейсу класу Abstraction(Figure)
	// in  abstract class Figure : virtual void DrawFigure() const = 0;
	virtual void DrawRectangle(int x, int y, int endx, int endy) = 0; 
};

