#include "CGlass.h"

CGlass::CGlass(int capacity)
	:m_capacity((capacity >= 0) ? capacity : 0), 
	m_waterAmount(0)
{
}

CGlass::~CGlass()
{
}

// возвращаем вместимость стакана
int CGlass::GetCapacity() const
{
	return m_capacity;
}

// возвращаем количество воды в стакане
int CGlass::GetWaterAmount() const
{
	return m_waterAmount;
}

// добавляем воду в стакан, возвращая фактически добавленное количество
int CGlass::AddWater(int amount)
{
	if (amount < 0)
	{
		amount = 0;
	}
	// проверка на целочисленное переполнение при сложении и на переполнение стакана
	else if (
		(m_waterAmount + amount < m_waterAmount) ||
		(m_waterAmount + amount > m_capacity))
	{
		amount = m_capacity - m_waterAmount;
	}

	m_waterAmount += amount;
	return amount;
}

// выливаем воду из стакана, возвращаем фактически вылитое количество
int CGlass::PourWater(int amount)
{
	// нельзя вылить больше, чем имеется в наличии, а также отрицательное количество
	amount =
		(amount < 0) ? 0 :
		(m_waterAmount >= amount) ? amount : m_waterAmount;

	m_waterAmount -= amount;
	return amount;
}
