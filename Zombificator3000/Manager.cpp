#include "Manager.h"

Manager::Manager()
{
	this->company = make_unique<Company>();
	srand(time(0));
	this->company->GetRatioInfected();
}

void Manager::Run()
{
	for (int i = 0; i < this->nbDaysGame; i++) {

		for (auto &employee : *this->company->employees) {

			this->CalculIfZombified(&*employee);
			employee->HandleInfection();
		}

		this->UpdateSalary();

		this->company->CalculRatioInfected();
		this->company->CostSalaryTurn();
		
		if (!this->isGameOver) { this->DND(); this->ShowDay(i + 1); }
		this->CheckEndGame();

	}
	this->ShowEndGame();
}

void Manager::DND()
{
	int tmpDND = (rand() % 7)+1;
	tmpDND += (rand() % 7) + 1;
	if (tmpDND >= 12) { ApplyDND(true, 4); cout << "Oh no your have a really badluck, it's time to PlantVsZombie, +4 zombified !" << endl; }
	else if (tmpDND >= 7) { ApplyDND(false, 2); cout << "One of youre employee decide to take too many good time, +2 infected !" << endl; }
	else if (tmpDND >= 3) { ApplyDND(false, 1); cout << "You discover a kniffe and cut yourself, stupid guy... , +1 infected !" << endl;}
}

void Manager::ApplyDND(bool zombified, int nb) {
	int nbApply = 0;
	for (auto& employee : *this->company->employees) {
		if (employee->GetState() == Employee::SANE && nbApply < nb) employee->SetNewZombieficationState((zombified) ? Employee::ZOMBIFIED : Employee::INCUBATING);
		if (nb >= nbApply) break;
	}
}

void Manager::CheckEndGame()
{
	this->isGameOver = this->company->GetRatioInfected() >= 100;
}

void Manager::UpdateSalary()
{
	for (auto& employee : *this->company->employees) { employee->SetSalary((employee->CheckIsZombified()) ? this->company->GetmodifiedSalary() : this->company->GetmodifiedSalary()); }
}

void Manager::CalculIfZombified(Employee *employee)
{
	if (rand() % (this->company->employees->size() +1 ) <= this->company->GetRatioInfected()) employee->SetNewZombieficationState(Employee::INCUBATING);
}

void Manager::ShowDay(int day)
{
	cout << "Current day: " << day << "| Zombified: " << this->company->GetRatioInfected() << "%" << endl;
	cout << endl;
}

void Manager::ShowEndGame()
{
	cout << "You just finish with a total cost of your company: " << this->company->GetCostTotal() << "k" << endl;
}



