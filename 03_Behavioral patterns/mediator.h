#pragma once
#include<iostream>
#include<string>
using namespace std;

class Brain;
class BodyPart
{
private:
	Brain*_brain;
protected:
	string bodyPartDefin;
public:
	BodyPart(Brain*brain);
	void Signal();
};
class Leg :public BodyPart
{
private:
	char feeling[50];
public:
	Leg(Brain*brain);
	void FeelSomething();
	string WhatYouFeel();
	void Push();
};
class Eye:public BodyPart
{
private:
	char seeSomething[50];
public:
	Eye(Brain*brain);
	void SeeSomething();
	string WhatYouSee();
	void CloseEye();
	void LookAround();
};

class Brain
{
public:
	Leg*leg;
	Eye*eye;
	Brain();
	void CreateBodyParts();
	void RecieveSignal(BodyPart*bodyPart, string bodyName);
};
