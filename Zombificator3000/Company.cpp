#include "Company.h"

Company::Company()
{
	this->employees = *new vector<Employee>;
	for (int i = 0; i < this->nbEmployees; i++) {
		this->employees.push_back(*new Employee());
		this->employees[i].SetSalary(this->baseSalary);
	}
	this->employees[0].SetNewZombieficationState(Employee::INCUBATING);
	this->employees[0].SetSalary(this->modifiedSalary);
}

void Company::CostSalaryTurn()
{
	for (auto& employee : this->employees) {
		this->costTotalSalary += (employee.GetSalary()/228);
	}
}

float Company::GetRatioInfected()
{
	return this->ratioInfected;
}

float Company::GetCostTotal()
{
	return this->costTotalSalary;
}

void Company::CalculRatioInfected()
{
	int tmpRatio = 0;
	for (auto& employee : this->employees) {
		if (employee.CheckIsZombified()) tmpRatio++;
	}
	this->ratioInfected = (float)tmpRatio / this->employees.size() * 100;
}

float Company::GetBaseSalary()
{
	return this->baseSalary;
}

float Company::GetmodifiedSalary()
{
	return this->modifiedSalary;
}
