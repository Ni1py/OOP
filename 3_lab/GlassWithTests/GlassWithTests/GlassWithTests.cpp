#include "CGlass.h"
#include <iostream>
#include <assert.h>

using namespace std;

void TestGlassCreation()
{
	// проверяем свойства созданного стакана
	CGlass validGlass(10);

	assert(validGlass.GetCapacity() == 10);
	assert(validGlass.GetWaterAmount() == 0);

	// пытаемся создать скакан отрицательной вместимости
	CGlass invalidGlass(-10);

	assert(invalidGlass.GetCapacity() == 0);
	assert(invalidGlass.GetWaterAmount() == 0);

	cout << "Glass creation test is ok\n";
}

void TestAddingWater()
{
	// создаем стакан вместимостью 100 мл.
	CGlass someGlass(100);

	// добавляем в него воды по 1 мл, убеждаясь в невозможности переполнения
	for (int i = 1; i < 200; ++i)
	{
		const int addedWater = someGlass.AddWater(1);
		if (i <= someGlass.GetCapacity())
		{
			assert(addedWater == 1);
			assert(someGlass.GetWaterAmount() == i);
		}
		else
		{
			assert(addedWater == 0);
			assert(someGlass.GetWaterAmount() == someGlass.GetCapacity());
		}
	}

	CGlass anotherGlass(100);
	anotherGlass.AddWater(10);
	assert(anotherGlass.GetWaterAmount() == 10);

	// пытаемся добавить отрицательное количество воды
	const int addedWater = anotherGlass.AddWater(-10);
	assert(addedWater == 0);
	assert(anotherGlass.GetWaterAmount() == 10);

	cout << "Adding water test is ok\n";
}

void TestPouringWater()
{
	// создаем стакан
	CGlass glass(100);

	// наполняем его доверху
	glass.AddWater(glass.GetCapacity());
	assert(glass.GetWaterAmount() == glass.GetCapacity());

	// выливаем воду по 1 мл, убеждаясь в невозможности вылить больше, чем есть воды
	for (int i = glass.GetWaterAmount() - 1; i >= -100; --i)
	{
		const int pouredWater = glass.PourWater(1);

		if (i >= 0)
		{
			assert(pouredWater == 1);
			assert(glass.GetWaterAmount() == i);
		}
		else
		{
			assert(pouredWater == 0);
			assert(glass.GetWaterAmount() == 0);
		}
	}

	// создаем другой стакан
	CGlass anotherGlass(100);
	anotherGlass.AddWater(10);
	assert(anotherGlass.GetWaterAmount() == 10);

	// пытаемся добавить отрицательное количество воды
	const int pouredWater = anotherGlass.PourWater(-10);
	assert(pouredWater == 0);
	assert(anotherGlass.GetWaterAmount() == 10);

	cout << "Pouring water test is ok\n";
}

void TestIntegerOverflow()
{
	CGlass glass(100);
	glass.AddWater(10);
	assert(glass.GetWaterAmount() == 10);
	// пытаемся вызвать целочисленное переполнение
	const int addedWater = glass.AddWater(INT_MAX);
	assert(addedWater == glass.GetCapacity() - 10);
	assert(glass.GetWaterAmount() == glass.GetCapacity());

	CGlass anotherGlass(100);
	// пытаемся вызвать целочисленное переполнение
	const int pouredWater = anotherGlass.PourWater(INT_MAX);
	assert(pouredWater == 0);
	assert(anotherGlass.GetWaterAmount() == 0);

	cout << "Integer overflow test is ok\n";
}

int main(int argc, char* argv[])
{
	TestGlassCreation();
	TestAddingWater();
	TestPouringWater();
	TestIntegerOverflow();

	return 0;
}
