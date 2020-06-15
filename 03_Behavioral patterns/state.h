#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<windows.h>
#include<conio.h>

using namespace std;
class IState;
class Car
{
	IState*_state;
public:
	Car();
	int petrol;
	void SetState(IState*state);
	void AddPetrol(int l);
	void Run();
	void Stop();
	void GoToAZS();
};
 class IState
{
protected: Car* _car;
public:
	IState(Car *car);
	virtual void AddPetrol(int l) = 0;
	virtual void Run() = 0;
	virtual void Stopping() = 0;
	virtual void GoToTheAZS() = 0;
};

class OnPetrolStationState :virtual public  IState
{
public:
	OnPetrolStationState(Car *car);
	void AddPetrol(int l);
	void Stopping();
	void Run();
	void GoToTheAZS();
};

class InRoadState :virtual public IState
{
public:
	InRoadState(Car *car);
	void AddPetrol(int l);
	void Stopping();
	void Run();
	void GoToTheAZS();
};
class StopState :virtual public IState
{
public:
	StopState(Car *car);
	void AddPetrol(int l);
	void Stopping();
	void Run();
	void GoToTheAZS();
};