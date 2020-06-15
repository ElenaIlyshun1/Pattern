#include<iostream>
#include<string>
#include<list>
#include<Windows.h>

using namespace std;


class IComponent//component
{
protected:
	int _salary;
public:
	string _name;
	string _department;
	virtual void AddNewComponent(IComponent*comp) = 0;
	virtual void GetData() = 0;
	virtual void GetChild() = 0;
};

class Employee :public IComponent
{
public:
	Employee(string name, int salary)
	{
		_name = name;
		_department = "";
		_salary = salary;
	}
	void AddNewComponent(IComponent*comp)
	{
		cout << "You cant add component to employee\n";
	}
	void GetData()
	{
		cout << this->_department << " person: " << this->_name << " salary - " << this->_salary << " grn\n";
	}
	void GetChild()
	{
		cout << "You cant add component to employee\n";
	}
};

class Depart :public IComponent
{
	
public:
	Depart(string dep)
	{
		this->_department = dep;
		this->_name = "";
	}
	list<IComponent*> list;
	static int counter;
	int numberDepart;
	void AddNewComponent(IComponent*comp)
	{
		list.push_back(comp);
		numberDepart = counter++;
	}
	void GetData()
	{
		cout << "Departament: " << this->_department <<endl;
		for (auto comp : list)
		{
			comp->GetData();
		}
	}
	void GetChild()
	{
		for (auto comp : list)
		{
			if(comp->_name=="")
			cout << comp->_department<<endl;
			if (comp->_department == "")
			cout << comp->_name<<endl;

		}
	}
};
int Depart::counter = 0;

void music() {
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(329, 500);
	Beep(247, 500);
	Beep(247, 500);
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(497, 500);
	Sleep(500);
	Beep(497, 500);
	Beep(277, 500);
	Beep(277, 500);
	Beep(440, 500);
	Beep(440, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(329, 500);
	Beep(247, 500);
	Beep(417, 500);
	Beep(417, 500);
	Beep(370, 500);
	Beep(417, 500);
	Beep(329, 500);
}

void main()
{
	music();
	Depart*firm = new Depart("firm");
	Depart*account = new Depart("account");
	Depart*worker = new Depart("worker");

	Employee*ivanova = new Employee("Ivanova", 5000);
	Employee*petrov = new Employee("petrov", 4800);
	Employee*pupkin = new Employee("pupkin", 5200);
	Employee*sidorov = new Employee("sidorov", 5000);

	Depart*workerNew = new Depart("branchOfWorker");

	firm->AddNewComponent(account);
	firm->AddNewComponent(worker);
	worker->AddNewComponent(workerNew);
	account->AddNewComponent(ivanova);
	worker->AddNewComponent(petrov);
	worker->AddNewComponent(pupkin);
	workerNew->AddNewComponent(sidorov);

	account->AddNewComponent(new Employee("zvetkov", 10000));

	IComponent*depNew = new Depart("New Managment!!!");
	depNew->AddNewComponent(new Employee("123", 1000));
	depNew->AddNewComponent(new Employee("555", 1000));
	depNew->AddNewComponent(new Employee("444", 1000));
	depNew->AddNewComponent(new Employee("789", 1000));
	account->AddNewComponent(depNew);

	firm->GetData();


	//worker->GetChild();
}