//#include"mediator.h"
//Eye::Eye(Brain*brain):BodyPart(brain)
//{
//	BodyPart::bodyPartDefin = "eye";
//}
//void Eye::SeeSomething()
//{
//	cout << "Enter what you see?";
//	cin.getline(seeSomething, 50);
//	Signal();
//}
//string Eye::WhatYouSee()
//{
//	return seeSomething;
//}
//void Eye::CloseEye() 
//{
//	cout << "I dont see nothing\n";
//}
//void Eye::LookAround() 
//{
//	cout << "I look around....I see sky....\n";
//}
//
//Leg::Leg(Brain*brain):BodyPart(brain)
//	{
//	BodyPart::bodyPartDefin = "leg";
//	}
//	void Leg::FeelSomething()
//	{
//		cout << "Enter what you feel?";
//		cin.getline(feeling, 50);
//		Signal();
//	}
//	string Leg::WhatYouFeel()
//	{
//		return feeling;
//	}
//	void Leg::Push()
//	{
//		cout << "I push you!!!!";
//	}
//	Brain::Brain()
//	{
//		CreateBodyParts();
//	}
//	void Brain::CreateBodyParts()
//	{
//		leg = new Leg(this);
//		eye = new Eye(this);
//	}
//	void Brain::RecieveSignal(BodyPart*bodyPart, string bodyName)
//	{
//		if (bodyName =="leg")
//		{
//			string feeling = leg->WhatYouFeel();
//			if (feeling == "paint")
//				leg->Push();
//		}
//	}
//	BodyPart::BodyPart(Brain*brain)
//	{
//		_brain = brain;
//	}
//	void BodyPart::Signal()
//	{
//		_brain->RecieveSignal(this,bodyPartDefin);
//	}
//
//
//
//
//void main()
//{
//	Brain *brain=new Brain();
//	brain->leg->FeelSomething();
//}