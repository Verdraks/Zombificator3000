#ifndef Company_h
#define Company_h

#include "Employee.h"

class Company
{
public:
	int nbEmployees = 100;
	vector<unique_ptr<Employee>> *employees;
	
	Company();
	~Company();

	void CostSalaryTurn();
	void CalculRatioInfected();

	float GetRatioInfected();
	float GetCostTotal();
	float GetBaseSalary();
	float GetmodifiedSalary();

private:
	float costTotalSalary = 0;
	float baseSalary = 26;
	float modifiedSalary = 45;
	float ratioInfected = 0;
};

#endif