#ifndef Manager_h
#define Manager_h

#include "Company.h"

class Manager
{
public:
	Manager();
	void Run();

private:
	void DND();
	void ApplyDND(bool zombified, int nb);
	void CheckEndGame();
	void UpdateSalary();
	void CalculIfZombified(Employee* employee);
	void ShowDay(int day);
	void ShowEndGame();

	int nbDaysGame = 28;
	bool isGameOver;
	unique_ptr<Company> company;
};
#endif