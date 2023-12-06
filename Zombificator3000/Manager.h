#ifndef Manager_h
#define Manager_h

#include "Company.h"

class Manager
{
public:
	Manager();
	void Run();

private:
	void CalculIfZombified(Employee& employee);
	void ShowDay();
	int nbDaysGame;
	Company company;
};

#endif // !Manager_h



