#ifndef  Company_h
#define Company_h

#include "Employee.h"
#include "Header.h"

class Company
{
public:
	int nbEmployees = 100;
	Company();
	void CostSalaryTurn();

private:
	int costSalary = 0;
	int baseSalary = 26;
	int modifiedSalary = 45;
	vector<Employee> employees;

};

#endif // ! Company



