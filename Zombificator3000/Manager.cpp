#include "Manager.h"

Manager::Manager()
{
	this->company = *new Company();
	srand(time(NULL));
}

void Manager::Run()
{
	for (int i = 0; i < this->nbDaysGame; i++) {

		for (auto& employee : this->company.employees) {

			CalculIfZombified(employee);
			employee.HandleInfection();
		}
	}
}

void Manager::CalculIfZombified(Employee &employee)
{
	if (rand() % (this->company.employees.size() + 1) <= this->company.GetRatioInfected()) employee.SetNewZombieficationState(Employee::INCUBATING);
}

