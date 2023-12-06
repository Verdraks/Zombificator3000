#pragma once
class Employee
{
public:

	Employee();

	enum ZombificationState {
		SANE,
		INCUBATING,
		ZOMBIFIED,
	};

	bool CheckIsZombified();
	void HandleInfection();
	ZombificationState GetState();
	void SetNewZombieficationState(ZombificationState newState);
	void SetSalary(int salary);
	float GetSalary();

private:
	static int index;
	float salary;
	int iD;
	int turnInfected;
	ZombificationState state;

};

