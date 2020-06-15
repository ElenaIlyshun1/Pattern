#include<iostream>
#include<string>
#include<list>


using namespace std;

class Image
{
public:

	int _key;
	string _path;
	Image(int key, string path)
	{
		_key = key;
		_path = path;
	}
};

class Factory
{
	static list<Image*> images;
public:
	static Image* GetImage(int key, string path)
	{
		for (auto img : images)
		{
			if (img->_key == key)
				return img;
		}
		Image* newImg = new Image(key, path);
		cout << "\nload new img\n";
		images.push_back(newImg);
		return newImg;
	}
};
list<Image*> Factory::images = {};

class Unit
{
	string _name;
	Image *img;
public:
	Unit(string name, int keyImg, string path)
	{
		_name = name;
		img = Factory::GetImage(keyImg, path);
	}

	void Show()
	{
		cout << "created object\n";
		cout << _name << " path image:" << img->_path << endl;
	}
};
//
//void main()
//{
//	Unit*u1 = new Unit("Goblin", 1, "D://goblin.obj");
//	u1->Show();
//	Unit*u2 = new Unit("Mirracle", 2, "D://mir.obj");
//	u2->Show();
//	Unit*u3 = new Unit("Terrorist", 3, "D://ter.obj");
//	u3->Show();
//	Unit*u4 = new Unit("Goblin", 1, "D://goblin.obj");
//	u4->Show();
//
//
//}