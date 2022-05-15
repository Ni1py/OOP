#pragma once

class CGlass
{
public:
	// создаем стакан заданной вместимости
	CGlass(int capacity);

	~CGlass();

	// возвращаем вместимость стакана
	int GetCapacity() const;

	// возвращаем количество воды в стакане
	int GetWaterAmount() const;

	// добавляем воду в стакан, возвращая фактически добавленное количество
	int AddWater(int amount);

	// выливаем воду из стакана, возвращаем фактически вылитое количество
	int PourWater(int amount);
private:
	int m_capacity;
	int m_waterAmount;
};
