#include <iostream>
#include <vector>
#include<Windows.h>
#include<string>
using namespace std;

class Ilog
{
public:
	virtual void Log(string msg) = 0;
};

class SimpleLog : public Ilog
{
public:
	void Log(string msg)
	{
		cout << __TIME__ << msg << endl;
	}
};

class ProductionLog : public Ilog
{
public:
	void Log(string msg)
	{
		cout <<"additional production info"<< __TIME__<< typeid(this).name() << msg << endl;
	}
};


enum LogType {SIMPLE, PRODUCTION};


class Logger
{
public:
	static Ilog* CreateLog(LogType type)
	{
		switch (type)
		{
		case LogType::PRODUCTION:
			return new ProductionLog();
			break;
		case LogType::SIMPLE:
			return new SimpleLog();
			break;
		}
		return new SimpleLog();
	}
};
void main()
{
	Ilog *log = Logger::CreateLog(LogType::PRODUCTION);
	log->Log("error on line 217");
	delete log;
}