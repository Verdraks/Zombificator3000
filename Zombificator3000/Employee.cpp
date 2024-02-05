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
    if (state == ZombificationState::INCUBATING) { if (turnInfected >= 2) state = ZombificationState::ZOMBIFIED; else this->turnInfected++; }
}

Employee::ZombificationState Employee::GetState()
{
    return state;
}

void Employee::SetNewZombieficationState(ZombificationState newState)
{
    state = newState;
}

void Employee::SetSalary(int salary)
{
    this->salary = salary;
}

float Employee::GetSalary()
{
    return this->salary;
}
