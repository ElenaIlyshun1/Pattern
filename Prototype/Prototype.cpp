#include<iostream>
#include "Car.h"
#include<time.h>

using namespace std;

int main() {

	// ������ ������
	string manufacturer;
	cout << endl << "Input manufacturer of car:" << endl;
	std::getline(std::cin, manufacturer);

	string description;
	cout << "Input description of car:" << endl;
	std::getline(std::cin, description);

	string color;
	cout << "Input color of car:" << endl;
	std::getline(std::cin, color);

	int year;
	cout << "Input year of car:" << endl;
	cin >> year;
	system("cls");
	// �������� ������
	Car c(manufacturer, description, color, year);
	//Car c;

	cout << "Let's clone!\nLet's prototype!" << endl;

	// ��������� ������
	Car* copy = (Car*)c.Clone();
	Car* copy2 = (Car*)c.Clone();
	
	// ������� ������������� ������

	copy->SetColor("white");
	copy2->SetName("Mersedes");

	c.Show();
	copy->Show();
	copy2->Show();
	delete copy;
	delete copy2;
	return 0;
}