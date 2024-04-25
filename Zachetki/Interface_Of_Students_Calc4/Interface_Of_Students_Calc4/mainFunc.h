#pragma once
#include "func.h"

void mainMenu();

void ExittheProgramm();

void PrintAllStudents(Student** pStudentsList);
void PrintCertainStudent(Student** mainListofStudent);
void PrintAllStudentbyNameAndEct(Student** msainListofStudent);

void ChangeStateCertainStudent(Student** mainListofStudent);
void ChangingStudentData(Student** mainListofStudent);

void DeleteCertainStudent(Student** mainListofStudents);
void DeleteAllStudent();

void AddNewStudent(Student** mainListofStudents);

void SortList(Student** mainListofStudents);