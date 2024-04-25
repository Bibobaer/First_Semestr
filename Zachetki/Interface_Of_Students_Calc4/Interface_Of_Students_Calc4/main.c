#include "func.h"
#include "mainFunc.h"

int main() {
	setlocale(LC_ALL, "Rus");
	ListofStudents = (Student**)malloc(sizeof(Student*));
	if (!ListofStudents)
		return 1;
	*ListofStudents = NULL;
	mainMenu();
	return 0;
}