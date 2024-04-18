#include <iostream> 
#include <conio.h>
using namespace std;

#define MIN_TANK_VOLUME 20
#define MAX_TANK_VOLUME 120

class Tank
{
	const int VOLUME;
	double fuel_level;
public:
	const int get_VOLUME()const
	{
		return VOLUME;
	}
	double get_fuel_level()const
	{
		return fuel_level;
	}
	void fill(double amount)
	{
		if (amount < 0)return;
		if (fuel_level + amount < VOLUME)fuel_level += amount;
		else fuel_level = VOLUME;
		
	}
	double give_fuel(double amount)
	{
		if (amount < 0)return fuel_level;
		fuel_level -= amount;
		if (fuel_level < 0)fuel_level = 0;
		return fuel_level;
	}
	Tank(int volume):VOLUME
	(
		
	)
	{
		
		this->fuel_level = 0;
		cout << "Tank is ready" << this << endl;
	}

	void info()const
	{
		cout << "Tank volume: " << VOLUME << "liters.\n";
		cout << "Fuel level: " << fuel_level << "liters.\n";
	}
};



#define MIN_ENGINE_CONSUMPTION 3
#define MAX_ENGINE_CONSUMPTION 30
class Engine
{
	const double CONSUMPTION;
	double consumption_per_second;
	bool is_started;
public:
	double get_consumption()const
	{
		return CONSUMPTION;
	}
	double get_consumption_per_second()const
	{
		return consumption_per_second;
	}
	Engine(double consumption)
		:CONSUMPTION(
			consumption < MIN_ENGINE_CONSUMPTION ? MIN_ENGINE_CONSUMPTION :
			consumption > MAX_ENGINE_CONSUMPTION ? MAX_ENGINE_CONSUMPTION :
			consumption),
		consumption_per_second(CONSUMPTION * 3e-5),
		is_started(false)
	{
		//this->consumption_per_second = CONSUMPTION * 3e-5;
		cout << "Engine is ready: " << this << endl;
	}
	~Engine()
	{
		cout << "Engine is over: " << this << endl;
	}
	void start()
	{
		is_started = true;
	}
	void stop()
	{
		is_started = false;
	}
	bool started()const
	{
		return is_started;
	}
	void info()const
	{
		cout << "Consumpition: " << CONSUMPTION << " liters/100km" << endl;
		cout << "Consumpition: " << consumption_per_second << " liters/sec" << endl;
		cout << "" << (is_started ? "" : "") << endl;
	}
};

class Car
{
	Engine engine;
	Tank tank;
	bool driver_insade;
public:
	Car(int consumption = 10, int volume = 60) :engine(consumption), tank(volume), driver_insade(false)
	{
		cout << "Your car is ready to go" << endl;
	}
	~Car()
	{
		cout << "Your car is over" << endl;
	}

	void get_in()
	{
		driver_insade = true;
		panel();
	}
	void get_out()
	{
		driver_insade = false;
		cout << "Out of the car" << endl;
	}
	void control()
	{
		char key;
		do
		{
			key = _getch();
			switch (key)
			{
			case 13: driver_insade ? get_out() : get_in(); break;
			}
		} while (key != 27);
	}
	void info()const
	{
		engine.info();
		tank.info();
	}
	void panel()const
	{
		while (driver_insade)
		{
			system("CLS");
			cout << "Fuel level:\t" << tank.get_fuel_level() << " liters.\n";
			cout << "Engine is " << (engine.started() ? "started" : "stopped") << endl;	
		}
	}
};

void main()
{
	setlocale(LC_ALL, "");
	/*Tank tank(50);
	int fuel;
	do 
	{
		cout << "¬ведите обьем топлива: "; cin >> fuel;
		tank.fill(fuel);
		tank.info();
	} while (fuel > 0);
	string str;*/

	/*Engine engine(10);
	engine.info();*/

	Car bmw;
	bmw.info();
	bmw.control();
};