//#include<iostream>
//#include<list>
//using namespace std;
//
//class StateMemento//сумка
//{
//	int _level;
//public:
//	StateMemento(int level)
//	{
//		_level = level;
//	}
//	int GetLevel()
//	{
//		return _level;
//	}
//};
//class SaverCaretaker
//{
//	list<StateMemento*>_stateMemento;
//public:
//	void Saver(StateMemento*stateMemento)
//	{
//		_stateMemento.push_back(stateMemento);
//	}
//	StateMemento*LoadLevel()
//	{
//		if (_stateMemento.size() != 0)
//		{
//			StateMemento *state = _stateMemento.back();
//			_stateMemento.pop_back();
//			return state;
//		}
//		return nullptr;
//	}
//	~SaverCaretaker()
//	{
//		for (auto it = _stateMemento.begin(); it != _stateMemento.end(); it++)
//		{
//			if (*it != nullptr)
//				delete *it;
//		}
//	}
//};
//class Game
//{
//	int _level;
//public:
//	Game(int level)
//	{
//		_level = level;
//	}
//	void GameRun()
//	{
//		cout << "game run!!!You have " << _level << " level. You lose 1. It left "<<_level-1<<endl;
//		_level--;
//	}
//	StateMemento* Save()
//	{
//		cout << "Save\n";
//		return new StateMemento(_level);
//	}
//	void UnLoad(StateMemento*state)
//	{
//		cout << "back up\n";
//		_level = state->GetLevel();
//	}
//};
//void main()
//{
//	Game*tank = new Game(7);
//	SaverCaretaker*save = new SaverCaretaker();
//
//	tank->GameRun();
//	tank->GameRun();
//	save->Saver(tank->Save());//віддаємо дані на зберігання северу
//	tank->GameRun();
//	tank->GameRun();
//	tank->GameRun();
//	save->Saver(tank->Save());//віддаємо дані на зберігання северу
//
//
//	tank->GameRun();
//	tank->UnLoad(save->LoadLevel());//забираємо в сейвера дані
//	tank->UnLoad(save->LoadLevel());//забираємо в сейвера дані
//	tank->GameRun();
//	delete tank;
//	delete save;
//}