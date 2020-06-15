////#include<iostream>
////#include<string>
////#include<vector>
////#include<algorithm>
////#include<iterator>
////
////using namespace std;
//#include"observer.h"
//class Subscriber
//{
//protected:
//	Site*_site;
//	string _news;
//	string _name;
//public:
//	Subscriber(Site*site, string name)
//	{
//		_site = site;
//		_name = name;
//	}
//	virtual void Update() = 0;
//};
//
//class SubscriberForShort:public Subscriber
//{
//public:
//	SubscriberForShort(Site*site, string name):Subscriber(site,name)
//	{
//		_site = site;
//		_name = name;
//	}
//	void Update()
//	{
//		if (strstr(_site->SendNews().c_str(),"Рівн") == 0)
//		{
//			_news = _site->SendNews();
//			cout << _name << " recieve news: " << _news << endl;
//		}
//	}
//};
//
//class SubscriberForAll:public Subscriber
//{
//public:
//	SubscriberForAll(Site*site, string name):Subscriber(site,name)
//	{
//		_site = site;
//		_name = name;
//	}
//	void Update()
//	{
//		_news = _site->SendNews();
//		cout << _name << " recieve news: " << _news << endl;
//	}
//};
//
//	void Site:: Notify()
//	{
//		for (auto s : _subscribers)
//		{
//			s->Update();
//		}
//	}
//	Site::Site()
//	{
//		_news = "";
//	}
//	void Site::Attach(Subscriber* subscriber)
//	{
//		_subscribers.push_back(subscriber);
//	}
//	void Site::Detach(Subscriber* subscriber)
//	{
//		auto it=find(_subscribers.begin(), _subscribers.end(), subscriber);
//		if(it!=_subscribers.end())
//		_subscribers.erase(it);
//	}
//	void Site::SetNews(string news)
//	{
//		if (_news != news)
//		{
//			_news = news;
//			Notify();
//		}
//	}
//	string Site::SendNews()
//	{
//		return _news;
//	}
//	
//void main()
//{
//	SetConsoleOutputCP(1251);
//	Site*msdn = new Site();
//	Subscriber*vasja = new SubscriberForAll(msdn,"Vasja");
//	Subscriber*petja = new SubscriberForShort(msdn,"Petja");
//
//	msdn->Attach(vasja);
//	msdn->Attach(petja);
//
//	msdn->SetNews("Улюблені Фіксіки розважатимуть маленьких рівнян ");
//	msdn->SetNews("У Рівному з`ясували, де варто першочергово ставити дитмайданчики за бюджетний кошт");
//	msdn->Detach(vasja);
//	msdn->SetNews("Незаконне будівництво на Гайдамацькій продовжується");
//}