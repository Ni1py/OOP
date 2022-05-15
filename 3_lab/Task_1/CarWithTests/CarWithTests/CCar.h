#pragma once

using namespace std;

enum class Direction { forward, back, standing };

namespace Limit {
	enum
	{
		minSpeedBack = 0, maxSpeedBack = 20,
		minSpeed1 = 0, maxSpeed1 = 30,
		minSpeed2 = 20, maxSpeed2 = 50,
		minSpeed3 = 30, maxSpeed3 = 60,
		minSpeed4 = 30, maxSpeed4 = 90,
		minSpeed5 = 50, maxSpeed5 = 150,
	};
}

class CCar
{
public:
	CCar();

	bool IsTurnedOn() const;
	Direction GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool IsSetSpeed(int speed) const;
	bool IsSetGear(int gear) const;
	bool IsSetDirection(int gear) const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_statusEngine;
	Direction m_direction;
	int m_speed;
	int m_gear;

	void SetDirection();
};

