#pragma once
#include "Device.h"
#include<Windows.h>
#include<iomanip>
/*
 * ���������� ������� ���������� ����� Car
 */
class Car : public Device {
private:
	// �������� ������
	string manufacturer;
	string description;
	string color;

	int year;

public:
	// ������������
	Car():Car("No information","No description","No color",0){
		SetName("Car");
	}
	Car(string cmanufacturer, string cdescription, string ccolor, int cyear); 
public:
	// ��������������� �������
	int GetYear()const{
		return year;
	}
	string GetManufacturer()const{
		return manufacturer;
	}
	string GetDescription()const{
		return description;
	}
	string GetColor()const{
		return color;
	}

	void SetYear(int cyear){
		year = cyear;
	}
	void SetManufacturer(string cmanufacturer) {
		manufacturer = cmanufacturer;
	}
	void SetColor(string ccolor) {
		color = ccolor;
	}
	void SetDescription(string cdescription) {
		description = cdescription;
	}

	// ���������� ����������� ������� � �������
	Device* Clone()const;
	void Show() const;
};

// ���������� ������������
Car::Car(string cmanufacturer, string cdescription, string ccolor, int cyear) {
	SetName("Car");

	SetManufacturer(cmanufacturer);
	SetDescription(cdescription);
	SetColor(ccolor);
	SetYear(cyear);
}

// ������� ������������
Device* Car::Clone() const{
	Car* tempCar = new Car();

	/* �������� ��������!
	 * ��� ��� ������ � ������������ ������� ����� ����������
	 * ����������� �����������, ����������� ��������
	 * � ����������� �������� = 
	 */	

	*tempCar = *this;
	return tempCar;
}

// ����������� �� ����� ������
void Car::Show() const{
	Device::Show();
	for (size_t i = 0; i < 50; i++)
	{

	}
	cout << char(218);
	HANDLE hcom = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcom, 11);
	for (int i = 0; i < 40; i++)
	{
		cout << char(196);
	}
	cout << char(191) << endl;
	cout << char(124);
	SetConsoleTextAttribute(hcom, 7);
	cout << setw(20) << "Description of car is   "<<setw(16) << GetDescription();
	SetConsoleTextAttribute(hcom, 11);
	cout << char(124)<< "\n"<< char(124);
	SetConsoleTextAttribute(hcom, 7);
	cout << setw(20) << "Manufacturer of car is   " << setw(15)<< GetManufacturer() ;
	SetConsoleTextAttribute(hcom, 11);
	cout << char(124) << "\n" << char(124);
	SetConsoleTextAttribute(hcom, 7);
	cout << setw(20) << "Year of car is   " << setw(20) << GetYear();
	SetConsoleTextAttribute(hcom, 11);
	cout << char(124) << "\n" << char(124);
	SetConsoleTextAttribute(hcom, 7);
	cout << setw(20) << "Color of car is   " << setw(20) << GetColor();
	SetConsoleTextAttribute(hcom, 11);
	cout << char(124) << "\n";
	cout << char(192);
	for (int i = 0; i < 40; i++)
	{
		cout << char(196);
	}
	cout << char(217) << endl;;
}

