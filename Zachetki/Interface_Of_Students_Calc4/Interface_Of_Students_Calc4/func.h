#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <limits.h>

#define MAX_LEN_OF_STRING	100
#define MAX_LEN_FOR_SE	10

typedef struct {
	char* name;
	char* surname;
	time_t Date_of_Birth;
	time_t Date_of_Receipt;
	time_t Date_of_Planned_Release;
	int state;
}Student;

Student** ListofStudents;

void* CreateObject(unsigned int SizeofObjectInBytes);

void PrintStudent(Student* student);

int CountOfStudent(Student** pStudentList);

void InitStudent(Student* pStudent, char* firstName, char* secondName, struct tm* pDoB , struct tm* pDoA, struct tm* pDoG, int state);
Student** AddStudent(Student** pStudentsList, Student* pNewStudent);
int AddStudentFromConsole(Student** pStudentsList);
int AddStudentFromFile(Student** pStudentsList, const char* filePath);

Student** FindStudentByName(Student** pStudentsList, char* name);
Student** FindStudentBySurname(Student** pStudentsList, char* surname);
Student** FindStudentByBirthDate(Student** pStudentsList, time_t DoB);
Student** FindStudentByState(Student** pStudentsList, int state);

void DeleteStudentFromList(Student** pStudentsList, Student** pTargetStudent);
int DeleteStudent(Student* pStudent);

int ChangeState(Student* pStudent, int newState);

void Swap_Students(Student* S1, Student* S2);