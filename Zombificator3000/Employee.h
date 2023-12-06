#pragma once
class Employee
{
public:

	Employee(int index);

	enum ZombificationState {
		SANE,
		INCUBATING,
		ZOMBIFIED,
	};

	bool CheckIsZombified();
	void HandleInfection();
	void SetNewZombieficationState(ZombificationState newState);
	void SetSalary(int salary);
	float GetSalary();

private:
	float salary;
	int iD;
	int turnInfected;
	ZombificationState state;

};

