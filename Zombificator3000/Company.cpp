#include "Company.h"

Company::Company()
{
	this->employees = *new vector<Employee>;
	for (int i = 0; i < this->nbEmployees; i++) {
		this->employees.push_back(*new Employee(i));
		this->employees[i].SetSalary(this->baseSalary);
	}
	this->employees[0].SetNewZombieficationState(Employee::ZOMBIFIED);
	this->employees[0].SetSalary(this->modifiedSalary);
}

void Company::CostSalaryTurn()
{
}
