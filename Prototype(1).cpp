//
//#include <iostream>
//#include<string>
//
//using namespace std;
//
//struct DateTime
//{
//	int day;
//	int month;
//	int year;
//	void ShowDate()
//	{
//		cout << day << ":" << month << ":" << year << endl;
//	}
//};
//class CalendarPrototype
//{
//public:
//	virtual CalendarPrototype* Clone() = 0;
//	virtual void ShowEvent() = 0;	
//};
//
//class Calendar : public CalendarPrototype
//{
//public:
//	string eventName;
//	DateTime* date;
//	CalendarPrototype * Clone()
//	{
//		return new Calendar(*this);
//	}
//	void ShowEvent()
//	{
//		cout << eventName<<" ";
//		date->ShowDate();
//	}
//	virtual ~Calendar() { delete date; }
//};
//
//class CalendarCreator
//{
//public:
//	static Calendar * GetExistingCalendar()
//	{
//		auto event = new Calendar();
//		event->eventName = "Birthday Oleg";
//		event->date = new DateTime();
//		event->date->day = 12;
//		event->date->month = 6;
//		event->date->year = 2018;
//		return event;
//	}
//	~CalendarCreator(){}
//};
//
//
//void main()
//{
//	auto event1 = CalendarCreator::GetExistingCalendar();
//	auto event2 = event1->Clone();
//	event1->ShowEvent();
//	event2->ShowEvent();
//	event1->eventName = "birthday Ira";
//	event1->date->day = 22;
//	event1->ShowEvent();
//	event2->ShowEvent();
//	delete event1;
//	delete event2;
//}
