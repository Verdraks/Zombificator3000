#include "Company.h"

Company::Company()
{
	this->employees = new vector<unique_ptr<Employee>>();
	for (int i = 0; i < nbEmployees; i++) {
		employees->push_back(make_unique<Employee>());
		(*employees)[i]->SetSalary(this->baseSalary);
	}

	(*employees)[0]->SetNewZombieficationState(Employee::INCUBATING);
	(*employees)[0]->SetSalary(this->modifiedSalary);
}

Company::~Company() {
	delete this->employees;
	this->employees = nullptr;
}

void Company::CostSalaryTurn()
{
	for (auto& employee : *this->employees) {
		this->costTotalSalary += (employee->GetSalary()/228);
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
	for (auto& employee : *this->employees) {
		if (employee->CheckIsZombified()) tmpRatio++;
	}
	this->ratioInfected = (float)tmpRatio / this->employees->size() * 100;
}

float Company::GetBaseSalary()
{
	return this->baseSalary;
}

float Company::GetmodifiedSalary()
{
	return this->modifiedSalary;
}