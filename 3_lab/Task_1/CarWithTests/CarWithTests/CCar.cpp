#include "CCar.h"
#include <string>
#include <iostream>

int Limit[6][2]{
	{0, 20},
	{0, 30},
	{20, 50},
	{30, 60},
	{30, 90},
	{50, 150}
};

CCar::CCar()
	:m_statusEngine(false),
	m_direction(Direction::standing),
	m_speed(0),
	m_gear(0)
{

}

bool CCar::IsTurnedOn() const
{
	return m_statusEngine;
}

Direction CCar::GetDirection() const
{
	return m_direction;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

int CCar::GetGear() const
{
	return m_gear;
}

bool CCar::IsSetDirection(int gear) const
{
	switch (gear)
	{
	case -1:
		return ((m_direction == Direction::back) || (m_direction == Direction::standing));
	case 0:
		return true;
	case 1:
		return ((m_direction == Direction::standing) || (m_direction == Direction::forward));
	}
	for (size_t i = 2; i < 6; i++)
		if (gear == i)
			return m_direction == Direction::forward;
	return false;
}

bool CCar::IsSetGear(int gear) const
{
	switch (gear)
	{
	case -1:
		return (m_speed == Limit[0][0] && IsTurnedOn());
	case 0:
		return true;
	}
	for (size_t i = 1; i < 6; i++)
		if (i == gear)
			return ((m_speed >= Limit[i][0]) && (m_speed <= Limit[i][1]) && IsTurnedOn());
	return false;
}

bool CCar::IsSetSpeed(int speed) const
{
	switch (m_gear)
	{
	case -1:
		return ((speed >= Limit[0][0]) && (speed <= Limit[0][1]));
	case 0:
		return speed <= m_speed;
	}
	for (size_t i = 1; i < 6; i++)
		if (i == m_gear)
			return ((speed >= Limit[i][0]) && (speed <= Limit[i][1]));
	return false;
}

bool CCar::TurnOnEngine()
{
	m_statusEngine = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if ((m_gear != 0) || (m_speed != 0))
		return false;
	m_statusEngine = false;
	return true;
}

void CCar::SetDirection()
{
	if ((m_gear == -1) && (m_speed > 0))
		m_direction = Direction::back;
	else if ((m_gear > 0) && (m_speed > 0))
		m_direction = Direction::forward;
	else if (m_speed == 0)
		m_direction = Direction::standing;
}

bool CCar::SetGear(int gear)
{
	if (!IsSetGear(gear) || !IsSetDirection(gear))
		return false;
	m_gear = gear;
	SetDirection();
	return true;
}

bool CCar::SetSpeed(int speed)
{
	if (speed < 0 || !IsTurnedOn() || !IsSetSpeed(speed))
		return false;
	m_speed = speed;
	SetDirection();
	return true;
}

