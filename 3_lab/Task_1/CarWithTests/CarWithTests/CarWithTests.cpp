#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "CCar.h"
#include "CControlCar.h"

using namespace std;

const string forwardTo = "forward";
const string back = "back";
const string standing = "stand in place";
const string creation = "\nCar creation test is ok\n";
const string turnOn = "\nTurning on engine test is ok\n";
const string turnOff = "\nTurning off engine test is ok\n";
const string gear = "\nSetting gear test is ok\n";
const string speed = "\nSetting speed test is ok\n";

void TestCarCreation()
{
	CCar validCar;

	assert(validCar.IsTurnedOn() == false);
	assert(validCar.GetDirection() == Direction::standing);
	assert(validCar.GetSpeed() == 0);
	assert(validCar.GetGear() == 0);

	cout << creation;
}

void TestTurningOnEngine()
{
	CCar someCar;

	assert(someCar.TurnOnEngine() == true);
	assert(someCar.GetGear() == 0);
	assert(someCar.GetSpeed() == 0);

	cout << turnOn;
}

void TestTurningOffEngine()
{
	CCar someCar;

	assert(someCar.TurnOffEngine() == true);
	assert(someCar.GetGear() == 0);
	assert(someCar.GetSpeed() == 0);

	CCar anotherCar;

	anotherCar.TurnOnEngine();                                   //
	assert(anotherCar.SetGear(1) == true);                       //выключить двигатель невозможно из-за 1 передачи
	assert(anotherCar.TurnOffEngine() == false);                 //

	anotherCar.SetSpeed(20);                                     //
	anotherCar.SetGear(0);                                       //выключить двигатель невозможно из-за ненулевой скорости
	assert(anotherCar.TurnOffEngine() == false);                 //

	cout << turnOff;
}

void TestSettingGear()
{
	CCar someCar;

	assert(someCar.SetGear(1) == false);                        //
	assert(someCar.GetGear() == 0);                             // без включения двигателя переключать на не 0 передачу нельзя
	assert(someCar.GetDirection() == Direction::standing);      //

	assert(someCar.SetGear(0) == true);                         //
	assert(someCar.GetGear() == 0);                             // без включения двигателя переключать на 0 передачу можно
	assert(someCar.GetDirection() == Direction::standing);      //

	someCar.TurnOnEngine();                                     //
	assert(someCar.SetGear(1) == true);                         // валидное переключение на 1 передачу, стоит на месте
	assert(someCar.GetGear() == 1);                             //
	assert(someCar.GetDirection() == Direction::standing);      //

	assert(someCar.SetGear(2) == false);                        //
	assert(someCar.GetGear() == 1);                             // на 2 передачу невалидное так как скорость не та, так же стоит на месте
	assert(someCar.GetDirection() == Direction::standing);       //

	someCar.SetSpeed(20);                                       //
	assert(someCar.SetGear(-1) == false);                       // переключение с 1 на заднюю невозможно так как ненулевая скорость
	assert(someCar.GetGear() == 1);                             // 
	assert(someCar.GetDirection() == Direction::forward);       //

	someCar.SetGear(1);                                         //
	someCar.SetSpeed(0);                                        //
	assert(someCar.SetGear(-1) == true);                        //
	someCar.SetSpeed(10);                                       // переключение из нейтралки на скорости в заднюю невозможно так как скорость ненулевая
	assert(someCar.SetGear(0) == true);                         //
	assert(someCar.GetGear() == 0);                             //
	assert(someCar.GetDirection() == Direction::back);          //
	assert(someCar.SetGear(-1) == false);                       //

	someCar.SetSpeed(0);                                        //
	assert(someCar.SetGear(-1) == true);                        //
	assert(someCar.GetGear() == -1);                            // переключение с задней на скорости на 1 невозможно так как ненулевая скорость
	someCar.SetSpeed(10);                                       //
	assert(someCar.GetDirection() == Direction::back);          //
	assert(someCar.SetGear(1) == false);                        //

	someCar.SetSpeed(0);                                        //
	assert(someCar.SetGear(1) == true);                         //
	assert(someCar.GetGear() == 1);                             // переключение с задней на 1 возможно так как скорость 0
	assert(someCar.GetDirection() == Direction::standing);      //

	someCar.SetGear(-1);                                        //
	someCar.SetSpeed(10);                                       //
	someCar.SetGear(0);                                         // переключение с нейтралки на скорости в направлении назад на 1 невозможно так как ненулевая скорость
	assert(someCar.SetGear(1) == false);                        //
	assert(someCar.GetGear() == 0);                             //
	assert(someCar.GetDirection() == Direction::back);          //

	someCar.SetSpeed(0);                                        //
	assert(someCar.SetGear(1) == true);                         // переключение с нейтралки на скорости 0 в направлении назад на 1 возможно так как скорость 0
	assert(someCar.GetGear() == 1);                             // *****************непонятно как должна себя вести(спросить)
	assert(someCar.GetDirection() == Direction::standing);      //

	cout << gear;
}

void TestSettingSpeed() //отрицательную скорость не обработал
{
	CCar someCar;
	someCar.TurnOnEngine();

	assert(someCar.SetSpeed(5) == false); // на нейтралке нельзя увеличивать скорость
	assert(someCar.GetSpeed() == 0);

	someCar.SetGear(-1);
	assert(someCar.SetSpeed(20) == true); //проверка максимальной скорости на нейтралке
	assert(someCar.GetSpeed() == 20);

	assert(someCar.SetSpeed(0) == true);
	someCar.SetGear(1);
	assert(someCar.SetSpeed(30) == true); // проверка максимальной скорости на 1 передаче
	assert(someCar.GetSpeed() == 30);

	someCar.SetGear(2);
	assert(someCar.SetSpeed(50) == true); // проверка максимальной скорости на 2 передаче
	assert(someCar.GetSpeed() == 50);

	someCar.SetGear(3);
	assert(someCar.SetSpeed(60) == true); // проверка максимальной скорости на 3 передаче
	assert(someCar.GetSpeed() == 60);

	someCar.SetGear(4);
	assert(someCar.SetSpeed(90) == true); // проверка максимальной скорости на 4 передаче
	assert(someCar.GetSpeed() == 90);

	someCar.SetGear(5);
	assert(someCar.SetSpeed(150) == true); // проверка максимальной скорости на 5 передаче
	assert(someCar.GetSpeed() == 150);

	cout << speed;
}

int main()
{
	TestCarCreation();
	TestTurningOnEngine();
	TestTurningOffEngine();
	TestSettingGear();
	TestSettingSpeed();

	CCar car;

	CControlCar controlCar;
	controlCar.ControlCar(car);

	return 0;
}

