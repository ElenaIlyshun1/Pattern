//#include<iostream>
//#include<string>
//#include<list>
//
//using namespace std;
//
//class Component
//{
//protected:
//	string name;
//	int salary;
//	string departmant;
//public:
//	virtual void AddComponent(Component*comp) = 0;
//	virtual void GetComponent() = 0;
//	virtual void GetChild() = 0;
//
//};
//
//class Composite :public Component
//{
//	list<Component*> tree;
//public:
//	Composite()
//	{
//		tree = {};
//	}
//	void AddComponent(Component*comp)
//	{
//		tree.push_back(comp);
//	}
//	void GetComponent()
//	{
//		for (auto components : tree)
//		{
//			cout << "departament\n";
//			components->GetComponent();
//		}
//	}
//	void GetChild() {}
//};
//
//class Accounter :public Component
//{
//public:
//	Accounter(string name)
//	{
//		this->name = name;
//		departmant = "account";
//		salary = 5000;
//	}
//	void AddComponent(Component*comp)
//	{
//		cout << "you cant do it\n";
//	}
//	void GetComponent()
//	{
//			cout << "pepson: " << this->name << endl;
//			cout << "depart: " << this->departmant << endl;
//			cout << this->salary << " grn" << endl;
//	}
//	void GetChild() {}
//};
//void main()
//{
//	Composite*root = new Composite();
//	Composite*br1 = new Composite();
//	Composite*br2 = new Composite();
//	Accounter*acc1 = new Accounter("Ivanova");
//	Accounter*acc2 = new Accounter("Petrova");
//
//	root->AddComponent(br1);
//	root->AddComponent(br2);
//	br1->AddComponent(acc1);
//	br1->AddComponent(acc2);
//	root->GetComponent();
//}