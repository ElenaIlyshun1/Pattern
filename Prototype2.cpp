#include <iostream>
#include <string>

/* Prototype base class. */
class Multimedia
{
protected:
	std::string type;
	int value;

public:
	virtual Multimedia* clone() = 0;

	std::string getType()
	{
		return type;
	}

	int getValue()
	{
		return value;
	}
};

class Photo : public Multimedia
{
public:
	Photo(int size)
	{
		type = "Very big Photo";
		value = size;
	}

	Multimedia* clone()
	{
		return new Photo(*this);
	}
};

class MP3 : public Multimedia
{
public:
	MP3(int size)
	{
		type = "so big mp3";
		value = size;
	}

	Multimedia* clone()
	{
		return new MP3(*this);
	}
};

/* Factory that manages prorotype instances and produces their clones. */
class ObjectFactory
{
	static Multimedia* Photovalue1;
	static Multimedia* Photovalue2;
	static Multimedia* mp3value1;
	static Multimedia* mp3value2;

public:
	static void  initialize()
	{
		Photovalue1 = new Photo(100);
		Photovalue2 = new Photo(200);
		mp3value1 = new MP3(100);
		mp3value2 = new MP3(200);
	}

	static Multimedia* getPhotoValue1()
	{
		return Photovalue1->clone();
	}

	static Multimedia* getPhotoValue2()
	{
		return Photovalue2->clone();
	}

	static Multimedia* getmp3Value1()
	{
		return mp3value1->clone();
	}

	static Multimedia* getmp3Value2()
	{
		return mp3value1->clone();
	}

	static void deleter()
	{
		delete Photovalue1;
		delete Photovalue2;
		delete mp3value1;
		delete mp3value2;
	}
};

Multimedia* ObjectFactory::Photovalue1 = nullptr;
Multimedia* ObjectFactory::Photovalue2 = nullptr;
Multimedia* ObjectFactory::mp3value1 = nullptr;
Multimedia* ObjectFactory::mp3value2 = nullptr;

int main()
{
	ObjectFactory::initialize();
	Multimedia* photoClone1;
	Multimedia* photoClone2;
	Multimedia* photoClone3;
	Multimedia* mp3Arr[2];

	/* All the object were created by cloning the prototypes. */
	photoClone1 = ObjectFactory::getPhotoValue1();
	std::cout << photoClone1->getType() << ": " << photoClone1->getValue() <<"mB"<< std::endl;
	photoClone2 = ObjectFactory::getPhotoValue1();
	std::cout << photoClone2->getType() << ": " << photoClone2->getValue() << "mB" << std::endl;
	photoClone3 = ObjectFactory::getPhotoValue1();
	std::cout << photoClone3->getType() << ": " << photoClone3->getValue() << "mB" << std::endl;

	mp3Arr[0]= ObjectFactory::getmp3Value1();
	mp3Arr[1] = ObjectFactory::getmp3Value1();
	std::cout << mp3Arr[0]->getType() << ": " << mp3Arr[0]->getValue() << "mB" << std::endl;
	std::cout << mp3Arr[1]->getType() << ": " << mp3Arr[1]->getValue() << "mB" << std::endl;

	delete photoClone1;
	delete photoClone2;
	delete photoClone3;
	delete mp3Arr[0];
	delete mp3Arr[1];
	ObjectFactory::deleter();
	return 0;
}
