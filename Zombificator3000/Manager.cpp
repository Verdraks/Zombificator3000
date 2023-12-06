#include "Manager.h"

Manager::Manager()
{
	this->company = *new Company();
	srand(time(0));
	this->company.GetRatioInfected();
}

void Manager::Run()
{
	for (int i = 0; i < this->nbDaysGame; i++) {

		for (auto &employee : this->company.employees) {

			this->CalculIfZombified(&employee);
			employee.HandleInfection();
		}

		this->UpdateSalary();

		this->company.CalculRatioInfected();
		this->company.CostSalaryTurn();
		this->ShowDay(i + 1);
		this->CheckEndGame();
		if (this->isGameOver) break;
	}
	this->ShowEndGame();
}

void Manager::CheckEndGame()
{
	this->isGameOver = this->company.GetRatioInfected() >= 100;
}

void Manager::UpdateSalary()
{
	for (auto& employee : this->company.employees) { employee.SetSalary((employee.CheckIsZombified()) ? this->company.GetmodifiedSalary() : this->company.GetmodifiedSalary()); }
}

void Manager::CalculIfZombified(Employee *employee)
{
	if (rand() % (this->company.employees.size() + 1) <= this->company.GetRatioInfected()) employee->SetNewZombieficationState(Employee::INCUBATING);
}

void Manager::ShowDay(int day)
{
	cout << "Current day: " << day << "| Infected: " << this->company.GetRatioInfected() << "%" << endl;
}

void Manager::ShowEndGame()
{
	cout << "You just finish with a total cost of your company: " << this->company.GetCostTotal() << "k" << endl;
}



