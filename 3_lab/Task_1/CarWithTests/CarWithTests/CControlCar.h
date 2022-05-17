#pragma once

#include "CCar.h"
#include <string>

class CControlCar
{
public:
	void ShowInfo(const CCar& car);
	void ControlCar(CCar car);
	std::string TextDirection(const CCar& car);
	std::string TextGear(const CCar& car);
private:
	void ToLowStr(string& str);
};

