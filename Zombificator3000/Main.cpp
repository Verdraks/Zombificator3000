#include "Manager.h"

void RunDiagnostic() {
	shared_ptr<Manager> manager = make_shared<Manager>();

	manager->Run();
}

int main() {

	RunDiagnostic();

	return 0;
}