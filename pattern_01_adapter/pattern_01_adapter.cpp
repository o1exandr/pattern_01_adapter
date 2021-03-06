/*
Завдання 1. Адаптер
Створити клас  Car з методами Start(), Stop(), Left(int angle), Right( int angle ).
Адаптувати клас  Car  до інтерфейсу  Консоль керування(CarConsole).

Інтерфейс  CarConsole пропонує методи Stop(), Run(),  Rotate(int angle), де angle - кут повороту авто, від’ємний кут означає поворот наліво, додатний - поворот направо.
Створити клас Водій(Driver), що вміє керувати авто з консоллю керування. Тобто  Водій  може керувати  довільним транспортним засобом, що підтримує інтерфейс CarConsole.


*/


#include "stdafx.h"
#include <iostream> 
#include <string>

using namespace std;

class Car
{
public:

	void Start()
	{
		cout << "Start\n";
	}

	void Stop()
	{
		cout << "Stop\n";
	}

	void Left(int angle)
	{
		cout << "Turn left on " << angle << endl;
	}

	void Right(int angle)
	{
		cout << "Turn right on " << angle << endl;
	}
};

class CarConsole : public Car
{
public:
	void Run()
	{
		Start();
	}

	void Stop()
	{
		Car::Stop();
	}

	void Rotate(int angle)
	{
		if (angle < 0)
			Left(angle);
		else
			Right(angle);
	}

};

class Driver
{
private:
	CarConsole cc;

public:

	void Run()
	{
		cc.Run();
	}

	void Stop()
	{
		cc.Stop();
	}

	void Rotate(int angle)
	{
		cc.Rotate(angle);
	}

};


int main()
{
	Driver d;
	d.Run();
	d.Rotate(-10);
	d.Rotate(20);
	d.Stop();


	cout << endl;
	system("pause");
	return 0;
}