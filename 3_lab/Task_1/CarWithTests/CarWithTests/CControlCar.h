#pragma once

#include "CCar.h"
#include <string>

class CControlCar
{
public:
	void ShowInfo(CCar const& car);
	void ControlCar(CCar car);
	std::string GetDirection(CCar const& car);
	std::string GerGear(CCar const& car);
};

