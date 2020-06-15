// #include"state.h"
//
//	Car::Car()
//	{
//		_state = new StopState(this);
//	}
//	void Car::SetState(IState*state)
//	{
//		_state = state;
//	}
//	void Car::AddPetrol(int l)
//	{
//		_state->AddPetrol(1);
//	}
//	void Car::Run()
//	{
//		_state->Run();
//	}
//	void Car::Stop()
//	{
//		_state->Stopping();
//}
//	void Car::GoToAZS()
//	{
//		_state->GoToTheAZS();
//	}
//	IState::IState(Car *car)
//	{
//		_car = car;
//	}
//
//
//	OnPetrolStationState::OnPetrolStationState(Car *car):IState(car)
//		 {		
//		 }
//		 void OnPetrolStationState::AddPetrol(int l)
//		 {
//			 while (!_kbhit())
//			 {
//				 system("cls");
//				 cout << "petrol ";
//				 _car->petrol += l;
//				 cout << _car->petrol << endl;
//				 Sleep(500);
//			 }
//			 _getch();
//			 if(_car->petrol>10)
//				 _car->SetState(new StopState(_car));
//		 }
//		 void OnPetrolStationState::Stopping()
//		 {
//			 cout << "You are already stopped\n";
//		 }
//		 void OnPetrolStationState::Run()
//		 {
//			 if (_car->petrol < 10)
//			 {
//				 cout << "Add the petrol befor running!!!!\n";
//				 AddPetrol(5);
//			 }
//			 else
//			 {
//				 cout << "Wait a minute....\n";
//				 cout << "You cant waiting a minute....Try again after finishing petrol adding\n";
//				 _car->SetState(new StopState(_car));
//			 }
//		 }
//		 void OnPetrolStationState::GoToTheAZS()
//		 {
//			 cout << "You are already on AZS\n";
//		 }
//
//
//	InRoadState::InRoadState(Car *car) :IState(car)
//	{
//	}
//	void InRoadState::AddPetrol(int l)
//	{
//		cout << "You cant add petrol in the road!!!!!\n";
//	}
//	void InRoadState::Stopping()
//	{
//		_car->SetState(new StopState(_car));
//		cout << "stop\n";
//	}
//	void InRoadState::Run()
//	{
//		cout << "You are already on the road\n";
//		}
//	void InRoadState::GoToTheAZS()
//	{
//		_car->SetState(new OnPetrolStationState(_car));
//	}
//	
//	StopState::StopState(Car *car) :IState(car)
//	{
//	}
//	void StopState::AddPetrol(int l)
//	{
//		cout << "Go to the petrol station\n";
//		_car->SetState(new OnPetrolStationState(_car));
//	}
//	void StopState::Stopping()
//	{
//		cout << "You are already stopped\n";
//	}
//	void StopState::Run()
//	{
//		if (_car->petrol < 5)
//		{
//			cout << "You cant run without petrol.Go to the AZS\n";
//		}
//		else
//		{
//			cout << "Wait a minute....\n";
//			while (!_kbhit())
//			{
//				system("cls");
//				cout << "You are on the road.Petrol left ";
//				_car->petrol -= 2;
//				cout << _car->petrol << endl;
//				Sleep(300);
//				if (_car->petrol < 5)
//				{
//					cout << "You cant run without petrol\n";
//					_car->SetState(new StopState(_car));
//					break;
//				}
//			}
//			_getch();
//			_car->SetState(new InRoadState(_car));
//		}
//	}
//	void StopState::GoToTheAZS()
//	{
//		_car->SetState(new OnPetrolStationState(_car));
//	}
//
//	void main()
//	{
//		Car car;/*
//		car.Run();
//		car.AddPetrol(10);
//		car.Stop();
//		car.AddPetrol(10);
//		car.Run();
//		car.Run();
//		car.Run();
//		car.Stop();
//		car.Run();*/
//		car.GoToAZS();
//		car.AddPetrol(5);
//		car.Run();
//		car.Run();
//		car.Stop();
//		car.AddPetrol(5);
//		car.AddPetrol(5);
//}