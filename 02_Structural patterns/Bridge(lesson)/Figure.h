#pragma once
#include "PaintApi.h"
// abstraction side(�������, ��� ����������)
class Figure
{
protected:
	PaintApi* api;// agregates pointer to interface of realization side class
public:

	Figure(PaintApi* pApi)
	{
		api = pApi;
	}

	virtual ~Figure()
	{
		if (api)
			delete api;
	}
	virtual void DrawFigure() const = 0;
};