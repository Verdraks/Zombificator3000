#ifndef  Company_h
#define Company_h

#include "Employee.h"
#include "Header.h"

class Company
{
public:
	int nbEmployees = 100;
	vector<Employee> employees;
	Company();
	void CostSalaryTurn();
	float GetRatioInfected();
	void CalculRatioInfected();

private:
	float costTotalSalary = 0;
	int baseSalary = 26;
	int modifiedSalary = 45;
	float ratioInfected;
};

#endif // ! Company



