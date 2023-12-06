#ifndef Manager_h
#define Manager_h

#include "Company.h"

class Manager
{
public:
	Manager();
	void Run();

private:
	void CheckEndGame();
	void UpdateSalary();
	void CalculIfZombified(Employee* employee);
	void ShowDay(int day);
	void ShowEndGame();
	int nbDaysGame = 28;
	bool isGameOver;
	Company company;
};

#endif // !Manager_h



