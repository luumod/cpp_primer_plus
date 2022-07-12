#include <iostream>
#include "tv友元类.h"

/*
友元类
*/
#if 0
bool Tv::volup()
{
	if (volume < MaxVal)
	{
		volume++;
		return true;
	}
	else
		return false;
}

bool Tv::voldown()
{
	if (volume > MinVal)
	{
		volume--;
		return true;
	}
	else
		return false;
}

void Tv::chanup()
{
	if (channel < maxchannel)
	{
		channel++;
	}
	else
	{
		channel = 1;
	}
}

void Tv::chandown()
{
	if (channel > 1)
	{
		channel--;
	}
	else
	{
		channel = maxchannel;
	}
}

void Tv::settings() const
{
	using std::cout; 
	using std::endl;
	cout << "TV is " << (state == OFF ? "Off" : "On ") << endl; 
	if (state == ON)
	{
		cout << "Volume setting = " << volume << endl; 
		cout << "Channel setting = " << channel << endl; 
		cout << "Mode = "
			<< (mode == Antrnna ? "antenna" : "cable") << endl; 
		cout << "Input = "
			<< (input == TV ? "TV" : "DVD") << endl;
	}
}
#endif
