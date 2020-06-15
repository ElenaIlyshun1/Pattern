//вжив для представлення запиту у вигляді обєкту, коли потрібно
// - класти запити в чергу
// - використати undo redu

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Developer
{
public:
	virtual void DoWork(string requestData) = 0;
};

class SingleHeroDeveloper:public Developer
{
public:
	void DoWork(string requestData)
	{
		cout << "I have done " << requestData <<" for a month!!!!"<< endl;
	}
};

class Team :public Developer
{
public:
	void DoWork(string requestData)
	{
		cout << "I have done " << requestData << " for a 2 days!!!!" << endl;
	}
};

class Request
{
private:
	Developer*_developer;
	string _requestData;
public:
	Request(Developer*developer, string requestData)
	{
		_developer = developer;
		_requestData = requestData;
	}
	void Execute()
	{
		_developer->DoWork(_requestData);
	}
	void UnExecute()
	{
		_developer->DoWork("stop");
	}
};
class DepartRequestAnalise
{
private:
	vector<Request*>_requests;
	vector<Request*>_history;

public:
	DepartRequestAnalise()
	{
		cout << "";
	}
	void AddOrder(Request*request)
	{
		_requests.push_back(request);
	}
	void DoWork(int ind)
	{
		if (_requests.size() == 0|| _requests.size()<=ind||ind<0)
		{
			cout << "nothing to work\n";
			return;
		}
		_requests.at(ind)->Execute();
		_history.push_back(_requests.at(ind));
		_requests.erase(_requests.begin() + ind, _requests.begin() + ind + 1);
	}
	void DoWork()
	{
		if (_requests.size() == 0)
		{
			cout << "nothing to work\n";
			return;
		}
		_requests.back()->Execute();
		_history.push_back(_requests.back());
		_requests.pop_back();
	}
	void Undo(int level)
	{
		for (auto el : _history)
		{
			el->Execute();
		}
	/*	for()
		_history->UnExecute();*/
	}
	void Redo(int level)
	{
		/*_history->Execute();*/
	}
};




void main()
{
	
	DepartRequestAnalise*orderTaker = new DepartRequestAnalise();
	
	Developer*petrov = new SingleHeroDeveloper();
	Developer*team = new Team();

	Request*game = new Request(petrov, "cool game");
	Request*game1 = new Request(petrov, "cool game1");
	Request*game2 = new Request(petrov, "cool game2");
	Request*game3 = new Request(petrov, "cool game3");

	Request*businessApl = new Request(team, "cool bussiness aplication!!");

	orderTaker->AddOrder(game);
	orderTaker->AddOrder(game1);
	orderTaker->AddOrder(game2);
	orderTaker->AddOrder(game3);
	orderTaker->AddOrder(game);
	orderTaker->DoWork();
	orderTaker->DoWork(2);
	orderTaker->DoWork();
	/*orderTaker->DoWork();
	orderTaker->DoWork();
	orderTaker->DoWork();
	orderTaker->DoWork(1);*/
	cout << "--------------------\n";
	orderTaker->Undo(5);

	//orderTaker->AddOrder(businessApl);
	//orderTaker->DoWork();
	//orderTaker->Redo();
	delete orderTaker;
}