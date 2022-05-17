#pragma once

using namespace std;

enum class Direction { back, standing, forward };

extern int Limit[6][2];

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

