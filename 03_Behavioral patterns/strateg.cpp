//
//#include<iostream>
//#include<string>
//#include<vector>
//#include<windows.h>
//#include<conio.h>
//using namespace std;
//class IMovable
//{
//public:
//	virtual void Move()=0;
//};
//
//class PetrolMove : public IMovable
//{
//public:
//	void Move()
//	{
//		cout << "Перемещение на бензине\n";
//	}
//};
//
//class ElectricMove :public IMovable
//{
//public:
//	void Move()
//	{
//		cout << "Перемещение на электричестве\n";
//	}
//};
//
//class Car
//{
//protected:
//	int passengers; // кол-во пассажиров
//	string model; // модель автомобиля
//	IMovable*movable;
//
//public:
//	Car(int num, string model, IMovable* mov)
//	{
//		this->passengers = num;
//		this->model = model;
//		SetMovable(mov);
//	}
//public:
//	IMovable*Movable() { return movable; }
//	void SetMovable(IMovable*m) { movable = m; }
//	void Move()
//	{
//		Movable()->Move();
//	}
//};
//
//void main() 
//{
//	SetConsoleOutputCP(1251);
//	//IMovable*move = new PetrolMove();
//	Car*car = new Car(4, "Volvo", new PetrolMove());
//	car->Move();
//	car->SetMovable(new ElectricMove());
//	car->Move();
//}