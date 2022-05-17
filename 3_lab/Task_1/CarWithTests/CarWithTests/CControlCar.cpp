#include "CControlCar.h"
#include <iostream>
#include <algorithm>

using namespace std;

const string reverseGear = "reverse";
const string neutralGear = "neutral";
const string firstGear = "first";
const string secondGear = "second";
const string thirdGear = "third";
const string fourthGear = "fourth";
const string fifthGear = "fifth";
const string back = "back";
const string forwardTo = "forward";
const string standing = "standing";
const string engineOn = "Engine condition: on";
const string engineOff = "Engine condition: off";
const string direction = "Direction: ";
const string speed = "Speed: ";
const string gear = "Gear: ";
const string beginText = "\nThe program for working with the Car.\n";
const string folText = "\nThe following functions are available to you:\n";
const string infoText = "* Info. - info about car\n";
const string engineOnText = "* EngineOn. - turn on the engine\n";
const string engineOffText = "* EngineOff. - turn off the engine\n";
const string gearText = "* SetGear <gear>. - set the gear\n";
const string speedText = "* SetSpeed <speed>. - set the speed\n";
const string exitText = "* exit. - exit\n";
const string errGear = "There is no such gear! ";
const string gearRange = "Gear range from -1 to 5.\n";
const string gearChange = "Gear changed to ";
const string gearChangeErr = "The gear could not be changed because ";
const string speedErr = "the speed does not fit the transmission range!";
const string directionErr = "the transmission does not fit the existing direction!";
const string invalidArgument = "Invalid argument! Please enter <int>.\n";
const string speedErrRange = "The speed cannot be less than 0!\n";
const string speedChange = "Speed changed to ";
const string speedChangeErr = "The speed could not be changed because ";
const string engineErr = "the engine is off.\n";
const string instructionErr = "There is no such instruction in the list!\n";
const string errEngine = "The engine cannot be turned off because ";
const string neutralErr = "the transmission is not neutral!\n";
const string zeroSpeedErr = "the speed is non-zero!";
const string infoPoint = "info.";
const string engineOnPoint = "engineon.";
const string engineOffPoint = "engineoff.";
const string setgear = "setgear";
const string setspeed = "setspeed";
const string exitPoint = "exit.";

void CControlCar::ToLowStr(string& str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
}


string CControlCar::TextGear(CCar const& car)
{
	switch (car.GetGear())
	{
	case -1:
		return reverseGear;
	case 0:
		return neutralGear;
	case 1:
		return firstGear;
	case 2:
		return secondGear;
	case 3:
		return thirdGear;
	case 4:
		return fourthGear;
	case 5:
		return fifthGear;
	}
}

string CControlCar::TextDirection(CCar const& car)
{
	switch (car.GetDirection())
	{
	case Direction::back:
		return back;
	case Direction::forward:
		return forwardTo;
	case Direction::standing:
		return standing;
	}
};

void CControlCar::ShowInfo(CCar const& car)
{
	cout << "\n";
	cout << (car.IsTurnedOn() ? engineOn : engineOff) << ".\n";
	cout << direction << TextDirection(car) << ".\n";
	cout << speed << car.GetSpeed() << ".\n";
	cout << gear << TextGear(car) << ".\n\n";
};

void CControlCar::ControlCar(CCar car)
{
	cout << beginText;
	cout << folText;
	cout << infoText;
	cout << engineOnText;
	cout << engineOffText;
	cout << gearText;
	cout << speedText;
	cout << exitText;

	string key = "";
	int i;

	while (true)
	{
		cin >> key;
		ToLowStr(key);
		if (key == infoPoint)
		{
			ShowInfo(car);
			continue;
		}
		else if (key == engineOnPoint)
		{
			car.TurnOnEngine();
			cout << engineOn << ".\n";
			continue;
		}
		else if (key == engineOffPoint)
		{
			if (car.TurnOffEngine())
			{
				cout << engineOff << ".\n";
				continue;
			}
			else
			{
				cout << errEngine;
				cout << (car.GetGear() != 0 ? neutralErr : "");
				cout << (car.GetSpeed() != 0 ? zeroSpeedErr : "");
				continue;
			}
		}
		else if (key == setgear)
		{
			cin >> i;
			if (!cin)
			{
				std::cout << invalidArgument;
				cin.clear();
				continue;
			}
			if (i < -1 || i > 5)
			{
				cout << errGear + gearRange;
				continue;
			}
			if (car.SetGear(i))
			{
				cout << gearChange << i << "\n";
				continue;
			}
			else
			{
				cout << gearChangeErr;
				cout << (!car.IsSetGear(i) ? speedErr : "") << "\n";
				cout << (!car.IsSetDirection(i) ? directionErr : "") << "\n";
				continue;
			}
		}
		else if (key == setspeed)
		{
			cin >> i;
			if (!cin)
			{
				std::cout << invalidArgument;
				cin.clear();
				continue;
			}
			if (i < 0)
			{
				cout << speedErrRange;
				continue;
			}
			if (car.SetSpeed(i))
			{
				cout << speedChange << i << ".\n";
				continue;
			}
			else
			{
				cout << speedChangeErr;
				cout << (!car.IsTurnedOn() ? engineErr : "");
				cout << (!car.IsSetSpeed(i) ? speedErr : "");
				continue;
			}
		}
		else if (key == exitPoint)
			break;

		cout << instructionErr;
	}
};

