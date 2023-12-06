#include "Employee.h"

int Employee::index = 0;

Employee::Employee()
{
    this->iD = Employee::index;
    Employee::index++;
    this->salary = 0;
    this->state = ZombificationState::SANE;
    this->turnInfected = 0;
}

bool Employee::CheckIsZombified()
{
    return this->state == ZombificationState::ZOMBIFIED;
}

void Employee::HandleInfection()
{
    if (this->state == ZombificationState::INCUBATING) { if (this->turnInfected >= 2) this->state = ZombificationState::ZOMBIFIED; else this->turnInfected++; }
}

void Employee::SetNewZombieficationState(ZombificationState newState)
{
    this->state = newState;
}

void Employee::SetSalary(int salary)
{
    this->salary = salary;
}

float Employee::GetSalary()
{
    return this->salary;
}
