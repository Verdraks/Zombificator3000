#include "Company.h"

Company::Company()
{
	this->employees = *new vector<Employee>;
	for (int i = 0; i < this->nbEmployees; i++) {
		this->employees.push_back(*new Employee());
		this->employees[i].SetSalary(this->baseSalary);
	}
	this->employees[0].SetNewZombieficationState(Employee::ZOMBIFIED);
	this->employees[0].SetSalary(this->modifiedSalary);
}

void Company::CostSalaryTurn()
{
	for (auto& employee : this->employees) {
		this->costTotalSalary += employee.GetSalary();
	}
}

float Company::GetRatioInfected()
{
	return this->ratioInfected;
}

void Company::CalculRatioInfected()
{
	int tmpRatio = 0;
	for (auto& employee : this->employees) {
		if (employee.CheckIsZombified()) tmpRatio++;
	}
	this->ratioInfected = (float)tmpRatio / (float)this->employees.size() * (float)100;
}
