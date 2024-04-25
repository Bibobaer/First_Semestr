#include "func.h"

void* CreateObject(unsigned int SizeofObjectInBytes) {
	void* ptr = malloc(SizeofObjectInBytes);
	if (!ptr) {
		exit(1);
	}
	return ptr;
}

void PrintStudent(Student* pStudent) {
	char tmp[MAX_LEN_FOR_SE];

	if (pStudent->state == 0)
		strcpy(tmp, "Studying");
	else if (pStudent->state == 1)
		strcpy(tmp, "Graduated");
	else
		strcpy(tmp, "Expelled");

	struct tm* DoB = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* DoA = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* DoG = (struct tm*)CreateObject(sizeof(struct tm));

	DoB = (struct tm*)pStudent->Date_of_Birth;
	DoA = (struct tm*)pStudent->Date_of_Receipt;
	DoG = (struct tm*)pStudent->Date_of_Planned_Release;
	printf("%s\n%s\n%02d.%02d.%d\n%02d.%02d.%d\n%02d.%02d.%d\n%s", pStudent->name, pStudent->surname, 
		DoB->tm_mday, DoB->tm_mon,DoB->tm_year, 
		DoA->tm_mday, DoA->tm_mon, DoA->tm_year, 
		DoG->tm_mday, DoG->tm_mon, DoG->tm_year, 
		tmp);
}



int CountOfStudent(Student** pStudentList) {
	int cnt = 0;
	int i = 0;
	while (pStudentList[i] != NULL) {
		cnt++;
		i++;
	}
	return cnt;
}

void InitStudent(Student* pStudent, char* firstName, char* secondName, struct tm* pDoB, struct tm* pDoA, struct tm* pDoG,int state) {
	pStudent->name = firstName;
	pStudent->surname = secondName;
	pStudent->Date_of_Birth = (time_t)pDoB;
	pStudent->Date_of_Receipt = (time_t)pDoA;
	pStudent->Date_of_Planned_Release = (time_t)pDoG;
	pStudent->state = state;
	return;
}

Student** AddStudent(Student** pStudentsList, Student* pNewStudent) {
	int cnt = CountOfStudent(pStudentsList);
	Student** tmp = (Student**)realloc(pStudentsList, (cnt+2)*sizeof(Student*)); 
	if (!tmp)
		exit(1);
	pStudentsList = tmp;
	pStudentsList[cnt] = pNewStudent;
	pStudentsList[cnt+1] = NULL;
	return pStudentsList;
}

int AddStudentFromConsole(Student** pStudentsList) {
	Student* newStudentfromConsole = (Student*)CreateObject(sizeof(Student));
	char* Name = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* Surname = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* tmp_for_state = (char*)CreateObject(MAX_LEN_FOR_SE);
	if (!Name || !Surname || !tmp_for_state)
		return 0;
	struct tm* DoB = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* DoA = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* DoG = (struct tm*)CreateObject(sizeof(struct tm));

	int State = 0;
	scanf_s("%s\n %s\n %d.%d.%d\n %d.%d.%d\n %s", Name, MAX_LEN_OF_STRING, Surname, MAX_LEN_OF_STRING, &DoB->tm_mday, &DoB->tm_mon, &DoB->tm_year,
		&DoA->tm_mday, &DoA->tm_mon, &DoA->tm_year, tmp_for_state, MAX_LEN_FOR_SE);

	DoG->tm_mday = DoA->tm_mday;
	DoG->tm_mon = (DoA->tm_mon + 6) % 12;

	if ((DoA->tm_mon + 6) > 12) {
		DoG->tm_year = DoA->tm_year + 6;
	}
	else {
		DoG->tm_year = DoA->tm_year + 5;
	}

	if (!strcmp(tmp_for_state, "Studying"))
		State = 0;
	else if (!strcmp(tmp_for_state, "Graduated"))
		State = 1;
	else if (!strcmp(tmp_for_state, "Expelled"))
		State = 2;
	else
		return 0;

	InitStudent(newStudentfromConsole, Name, Surname, DoB, DoA, DoG, State);
	ListofStudents = AddStudent(pStudentsList, newStudentfromConsole);
	return 1;
}

int AddStudentFromFile(Student** pStudentsList, const char* filePath) {
	FILE* file = fopen(filePath, "r");
	if (file == NULL) {
		printf("Неудалось открыть файл\n");
		return 0;
	}
	Student* newStudentfromFile = (Student*)CreateObject(sizeof(Student));
	char* Name = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* Surname = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* tmp_for_state = (char*)CreateObject(MAX_LEN_FOR_SE);
	if (!Name || !Surname || !tmp_for_state)
		return 0;
	struct tm* DoB = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* DoA = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* DoG = (struct tm*)CreateObject(sizeof(struct tm));

	int State = 0;
	fscanf_s(file, "%s\n %s\n %d.%d.%d\n %d.%d.%d\n %s", Name, MAX_LEN_OF_STRING, Surname, MAX_LEN_OF_STRING, &DoB->tm_mday, &DoB->tm_mon, &DoB->tm_year,
		&DoA->tm_mday, &DoA->tm_mon, &DoA->tm_year, tmp_for_state, MAX_LEN_FOR_SE);
	DoG->tm_mday = DoA->tm_mday;
	DoG->tm_mon = (DoA->tm_mon + 6) % 12;

	if ((DoA->tm_mon + 6) > 12){
		DoG->tm_year = DoA->tm_year + 6;
	} 
	else{
		DoG->tm_year = DoA->tm_year + 5;
	}

	if (!strcmp(tmp_for_state, "Studying"))
		State = 0;
	else if (!strcmp(tmp_for_state, "Graduated"))
		State = 1;
	else if (!strcmp(tmp_for_state, "Expelled"))
		State = 2;
	else
		return 0;

	InitStudent(newStudentfromFile, Name, Surname, DoB, DoA, DoG, State);
	ListofStudents = AddStudent(pStudentsList, newStudentfromFile);

	fclose(file);
	return 1;
}

Student** FindStudentByName(Student** pStudentsList, char* name) {
	Student** findList = CreateObject(sizeof(Student*));
	findList[0] = NULL;
	for (int i = 0; pStudentsList[i] != NULL; i++) {
		if (!strcmp(name, pStudentsList[i]->name)) {
			findList = AddStudent(findList, pStudentsList[i]);
		}
	}

	return findList;
}

Student** FindStudentBySurname(Student** pStudentsList, char* surname) {
	Student** findList = CreateObject(sizeof(Student*));
	findList[0] = NULL;
	for (int i = 0; pStudentsList[i] != NULL; i++) {
		if (!strcmp(surname, pStudentsList[i]->surname)) {
			findList = AddStudent(findList, pStudentsList[i]);
		}
	}

	return findList;
}

Student** FindStudentByBirthDate(Student** pStudentsList, time_t DoB) {
	Student** findList = CreateObject(sizeof(Student*));
	findList[0] = NULL;
	struct tm* StudentBD = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* FindBD = DoB;
	for (int i = 0; pStudentsList[i] != NULL; i++) {
		StudentBD = pStudentsList[i]->Date_of_Birth;
		if (FindBD->tm_mday == StudentBD->tm_mday && FindBD->tm_mon == StudentBD->tm_mon && FindBD->tm_year == StudentBD->tm_year) {
			findList = AddStudent(findList, pStudentsList[i]);
		}
	}

	return findList;
}

Student** FindStudentByState(Student** pStudentsList, int state) {
	Student** findList = CreateObject(sizeof(Student*));
	findList[0] = NULL;
	for (int i = 0; pStudentsList[i] != NULL; i++) {
		if (state == pStudentsList[i]->state) {
			findList = AddStudent(findList, pStudentsList[i]);
		}
	}
	return findList;
}


void DeleteStudentFromList(Student** pStudentsList, Student** pTargetStudent) {
	int cnt = 0;
	int CountStud = CountOfStudent(pStudentsList);
	for (int j = 0; pStudentsList[j] != *pTargetStudent; j++)
		cnt = j + 1;
	DeleteStudent(*pTargetStudent);
	for (int k = cnt; pStudentsList[k] != NULL; k++)
		pStudentsList[k] = pStudentsList[k + 1];
}

int DeleteStudent(Student* pStudent) {
	if (pStudent == 0)
		return 1;
	free(pStudent);
	return 0;
}

int ChangeState(Student* pStudent, int newState) {
	if (newState >= 0 && newState < 3) {
		pStudent->state = newState;
		return 1;
	}
	return 0;
}

void Swap_Students(Student* S1, Student* S2) {
	Student tmp = *S1;
	*S1 = *S2;
	*S2 = tmp;
}