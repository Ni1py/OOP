#include "CCar.h"
#include <string>
#include <iostream>

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
		return ((m_direction == Direction::standing) || (m_direction == Direction::back));
	case 0:
		return true;
	case 1:
		return ((m_direction == Direction::standing) || (m_direction == Direction::forward));
	case 2:
		return m_direction == Direction::forward;
	case 3:
		return m_direction == Direction::forward;
	case 4:
		return m_direction == Direction::forward;
	case 5:
		return m_direction == Direction::forward;
	default:
		return false;
	}
}

bool CCar::IsSetGear(int gear) const
{
	switch (gear)
	{
	case -1:
		return (m_speed == Limit::minSpeedBack && IsTurnedOn());
	case 0:
		return true;
	case 1:
		return ((m_speed >= Limit::minSpeed1) && (m_speed <= Limit::maxSpeed1) && IsTurnedOn());
	case 2:
		return ((m_speed >= Limit::minSpeed2) && (m_speed <= Limit::maxSpeed2) && IsTurnedOn());
	case 3:
		return ((m_speed >= Limit::minSpeed3) && (m_speed <= Limit::maxSpeed3) && IsTurnedOn());
	case 4:
		return ((m_speed >= Limit::minSpeed4) && (m_speed <= Limit::maxSpeed4) && IsTurnedOn());
	case 5:
		return ((m_speed >= Limit::minSpeed5) && (m_speed <= Limit::maxSpeed5) && IsTurnedOn());
	default:
		return false;
	}
}

bool CCar::IsSetSpeed(int speed) const
{
	switch (m_gear)
	{
	case -1:
		return ((speed >= Limit::minSpeedBack) && (speed <= Limit::maxSpeedBack));
	case 0:
		return speed <= m_speed;
	case 1:
		return ((speed >= Limit::minSpeed1) && (speed <= Limit::maxSpeed1));
	case 2:
		return ((speed >= Limit::minSpeed2) && (speed <= Limit::maxSpeed2));
	case 3:
		return ((speed >= Limit::minSpeed3) && (speed <= Limit::maxSpeed3));
	case 4:
		return ((speed >= Limit::minSpeed4) && (speed <= Limit::maxSpeed4));
	case 5:
		return ((speed >= Limit::minSpeed5) && (speed <= Limit::maxSpeed5));
	default:
		return false;
	}
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

