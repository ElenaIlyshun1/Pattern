//#include<iostream>
//#include<string>
//#include<list>
//
//
//using namespace std;
//
//class Image
//{
//public:
//
//	int _key;
//	string _path;
//	Image(int key, string path)
//	{
//		_key = key;
//		_path = path;
//	}
//};
//
//class Factory
//{
//	static list<Image*> images;
//public:
//	static Image* GetImage(int key, string path)
//	{
//		for (auto img : images)
//		{
//			if (img->_key == key)
//				return img;
//		}
//		Image* newImg = new Image(key, path);
//		cout << "\nload new img\n";
//		images.push_back(newImg);
//		return newImg;
//	}
//};
//list<Image*> Factory::images = {};
//
//class Unit
//{
//public:
//	string _name;
//	Image *img;
//	Unit()
//	{
//	}
//	virtual void CreateUnit(string name, int keyImg, string path) = 0;
//
//	virtual void Show() = 0;
//};
//
//class SharedUnit:public Unit
//{
//public:
//	SharedUnit()
//	{
//		
//	}
//	void CreateUnit(string name, int keyImg, string path)
//	{
//		_name = name;
//	}
//	void Show()
//	{
//		cout << "created object without image\n";
//	}
//};
//class UnSharedUnit:public Unit
//{
//	Unit*_u;
//public:
//	UnSharedUnit(Unit*u)
//	{
//		_u = u;		
//	}
//	void CreateUnit(string name, int keyImg, string path)
//	{
//		_u->img = Factory::GetImage(keyImg, path);
//	}
//	void Show()
//	{
//		_u->Show();
//		cout << "get image\n";
//		cout << _u->_name << " path image:" << _u->img->_path << endl;
//	}
//};
//
//
//void main()
//{
//	Unit*unit1 = new SharedUnit();
//	unit1->CreateUnit("Goblin", 1, "goblin.obj");
//	unit1->Show();
//
//	Unit*u2 = new UnSharedUnit(unit1);
//	u2->CreateUnit("Goblin", 1, "goblin.obj");
//	u2->Show();
//	cout << "\n--------------------------------\n";
//	Unit*unit3 = new SharedUnit();
//	unit3->CreateUnit("Goblin", 1, "goblin.obj");
//	unit3->Show();
//	Unit*u4 = new UnSharedUnit(unit3);
//	u4->CreateUnit("Goblin", 1, "goblin.obj");
//	u4->Show();
//}