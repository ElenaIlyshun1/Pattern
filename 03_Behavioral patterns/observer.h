#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<windows.h>

using namespace std;
class Subscriber;
class Site
{
	string _news;
	vector<Subscriber*> _subscribers;
	void Notify();
public:
	Site();
	void Attach(Subscriber* subscriber);
	void Detach(Subscriber* subscriber);
	void SetNews(string news);
	string SendNews();
};