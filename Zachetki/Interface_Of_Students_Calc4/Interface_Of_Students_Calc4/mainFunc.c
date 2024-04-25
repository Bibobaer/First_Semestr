#include "mainFunc.h"

void mainMenu() {
	char action = '0';
	while (1) {
		system("pause");
		system("cls");
		printf("1) Вывод данных всех студентов\n"
			"2) Поиск и вывод данных всех найденных студентов в списке по дате рождения, по имени, по фамилии, по состоянию обучения\n"
			"3) Вывод данных конкретного студента\n"
			"4) Вывод в отсортированном виде по имени, по фамилии, по дате рождения, по дате поступления, по состоянию обучения\n"
			"5) Добавление нового студента\n"
			"6) Изменение данных существующего студента\n"
			"7) Изменение состояния обучения конкретного студента\n"
			"8) Удаление конкретного студента из списка\n"
			"9) Очистка всего списка\n"
			"0) Выход из программы\n");
		scanf_s(" %c", &action, 1);
		switch (action)
		{
		case '0':
			ExittheProgramm();//+
			break;
		case '1':
			PrintAllStudents(ListofStudents);//+
			break;
		case '2':
			PrintAllStudentbyNameAndEct(ListofStudents);//+
			break;
		case '3':
			PrintCertainStudent(ListofStudents);//+
			break;
		case '4':
			SortList(ListofStudents);//+
			break;
		case '5':
			AddNewStudent(ListofStudents);//+
			break;
		case '6':
			ChangingStudentData(ListofStudents);//+
			break;
		case '7':
			ChangeStateCertainStudent(ListofStudents);//+
			break;
		case '8':
			DeleteCertainStudent(ListofStudents);//+
			break;
		case '9':
			DeleteAllStudent();//+
			break;
		default:
			break;
		}
	}
}
void ExittheProgramm() {
	printf("Вы вышли из программы\n");
	exit(0);
}

void PrintAllStudents(Student** pStudentsList) {
	system("cls");
	int cnt = CountOfStudent(pStudentsList);
	if (cnt == 0)
		printf("Список пустой\n");
	for (int i = 0; i < cnt; ++i) {
		PrintStudent(pStudentsList[i]);
		printf("\n\n");
	}
}

void PrintCertainStudent(Student** mainListofStudent) {
	system("cls");
	char* name = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* surname = (char*)CreateObject(MAX_LEN_OF_STRING);
	if (!name || !surname)
		exit(1);
	printf("Введите имя нужного студента: ");
	scanf_s("%s", name, MAX_LEN_OF_STRING);
	printf("Введите фамилию нужного студента: ");
	scanf_s("%s", surname, MAX_LEN_OF_STRING);
	Student** pStudPtr_1 = FindStudentByName(mainListofStudent, name);
	Student** pStudPtr_2 = FindStudentBySurname(mainListofStudent, surname);
	for (int i = 0; pStudPtr_1[i] != NULL; i++) {
		for (int j = 0; pStudPtr_2[j] != NULL; j++) {
			if (pStudPtr_1[i] == pStudPtr_2[j]) {
				PrintStudent(pStudPtr_1[i]);
			}
		}
	}
}

void PrintAllStudentbyNameAndEct(Student** mainListofStudent) {
	system("cls");
	char* name_or_surname = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* String_for_State = (char*)CreateObject(MAX_LEN_FOR_SE);
	time_t DoB = time(NULL);
	struct tm* t = (struct tm*)CreateObject(sizeof(struct tm));
	int state = 0;
	if (!name_or_surname)
		exit(1);
	char op = '0';
	printf("По какому значению вы хотите вывести студентов?\n1)по имени\n2)по фамилии\n3)по дате рождения\n4)по состоянию обучения\n");
	scanf_s(" %c", &op, 1);
	system("cls");
	Student** NeedfulStudents = NULL;
	switch (op)
	{
	case '1':
		printf("Введите имя:\n");
		scanf_s("%s", name_or_surname, MAX_LEN_OF_STRING);
		NeedfulStudents = FindStudentByName(mainListofStudent, name_or_surname);
		break;
	case '2':
		printf("Введите фамилию:\n");
		scanf_s("%s", name_or_surname, MAX_LEN_OF_STRING);
		NeedfulStudents = FindStudentBySurname(mainListofStudent, name_or_surname);
		break;
	case '3':
		printf("Введите дату рождения:\n");
		scanf_s("%d.%d.%d", &(*t).tm_mday, &(*t).tm_mon, &(*t).tm_year);
		DoB = (time_t)t;
		NeedfulStudents = FindStudentByBirthDate(mainListofStudent, DoB);
		break;
	case '4':
		printf("Введите состояние обучения:\n");
		scanf_s("%s", String_for_State, MAX_LEN_FOR_SE);
		if (!strcmp(String_for_State, "Studying"))
			state = 0;
		else if (!strcmp(String_for_State, "Graduated"))
			state = 1;
		else if (!strcmp(String_for_State, "Expelled"))
			state = 2;
		else
			return;
		NeedfulStudents = FindStudentByState(mainListofStudent, state);
		break;
	default:
		break;
	}
	PrintAllStudents(NeedfulStudents);
}

void ChangeStateCertainStudent(Student** mainListofStudent){
	system("cls");
	char* Tmp_State = (char*)CreateObject(MAX_LEN_FOR_SE);
	int state = 0;
	printf("Введите новое состояние английскими буквами: ");
	scanf_s("%s", Tmp_State, MAX_LEN_FOR_SE);
	if (!strcmp(Tmp_State, "Studying"))
		state = 0;
	else if (!strcmp(Tmp_State, "Graduated"))
		state = 1;
	else if (!strcmp(Tmp_State, "Expelled"))
		state = 2;
	else
		return;
	int cnt = CountOfStudent(mainListofStudent);
	char* name = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* surname = (char*)CreateObject(MAX_LEN_OF_STRING);
	Student* targetStudent = (Student*)CreateObject(sizeof(Student));
	printf("Введите имя нужного студента: ");
	scanf_s("%s", name, MAX_LEN_OF_STRING);
	printf("Введите фамилию нужного студента: ");
	scanf_s("%s", surname, MAX_LEN_OF_STRING);
	Student** pStudPtr_1 = FindStudentByName(mainListofStudent, name);
	Student** pStudPtr_2 = FindStudentBySurname(mainListofStudent, surname);
	for (int i = 0; pStudPtr_1[i] != NULL; i++) {
		for (int j = 0; pStudPtr_2[j] != NULL; j++) {
			if (pStudPtr_1[i] == pStudPtr_2[j]) {
				targetStudent = pStudPtr_1[i];
			}
		}
	}
	ChangeState(targetStudent, state);
}

void ChangingStudentData(Student** mainListofStudent) {
	system("cls");
	Student* targetStudent = (Student*)CreateObject(sizeof(Student));
	char* targetName = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* targetSurname = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* Tmp_State = (char*)CreateObject(MAX_LEN_FOR_SE);

	struct tm* tmDoB = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* tmDoA = (struct tm*)CreateObject(sizeof(struct tm));
	struct tm* tmDoG = (struct tm*)CreateObject(sizeof(struct tm));

	time_t DoB = 0;
	time_t DoA = 0;
	time_t DoG = 0;
	int state = 0;
	printf("Введите имя и фамилию нужного студента:\n");
	scanf_s("%s %s", targetName, MAX_LEN_OF_STRING, targetSurname, MAX_LEN_OF_STRING);
	Student** pStudPtr_1 = FindStudentByName(mainListofStudent, targetName);
	Student** pStudPtr_2 = FindStudentBySurname(mainListofStudent, targetSurname);
	for (int i = 0; pStudPtr_1[i] != NULL; i++) {
		for (int j = 0; pStudPtr_2[j] != NULL; j++) {
			if (pStudPtr_1[i] == pStudPtr_2[j]) {
				targetStudent = pStudPtr_1[i];
			}
		}
	}
	char op = '0';
	printf("Выберите то, что хотите изменить\n1)имя\n2)фамилия\n3)дата рождения\n4)дата поступления\n5)примерная дата окончания\n6)состояние обучения\n");
	scanf_s(" %c", &op, 1);

	switch (op)
	{
	case '1':
		printf("Введите новое имя студента\n");
		scanf_s("%s", targetName, MAX_LEN_OF_STRING);
		targetStudent->name = targetName;
		break;
	case '2':
		printf("Введите новую фамилию студента\n");
		scanf_s("%s", targetSurname, MAX_LEN_OF_STRING);
		targetStudent->surname = targetSurname;
		break;
	case '3':
		printf("Введите новоую дату рождения\n");
		scanf_s("%d.%d.%d", &(*tmDoB).tm_mday, &(*tmDoB).tm_mon, &(*tmDoB).tm_year);
		DoB = (time_t)tmDoB;
		targetStudent->Date_of_Birth = DoB;
		break;
	case '4':
		printf("Введите новую дату поступления\n");
		scanf_s("%d.%d.%d", &(*tmDoA).tm_mday, &(*tmDoA).tm_mon, &(*tmDoA).tm_year);
		DoA = (time_t)tmDoA;
		targetStudent->Date_of_Receipt = DoA;
		break;
	case '5':
		printf("Введите новую дату окончания\n");
		scanf_s("%d.%d.%d", &(*tmDoG).tm_mday, &(*tmDoG).tm_mon, &(*tmDoG).tm_year);
		DoG = (time_t)tmDoG;
		targetStudent->Date_of_Planned_Release = DoG;
		break;
	case '6':
		printf("Введите новое состояние обучения\n");
		scanf_s("%s", Tmp_State, MAX_LEN_FOR_SE);
		if (!strcmp(Tmp_State, "Studying"))
			state = 0;
		else if (!strcmp(Tmp_State, "Graduated"))
			state = 1;
		else if (!strcmp(Tmp_State, "Expelled"))
			state = 2;
		else
			return;
		ChangeState(targetStudent, state);
		break;
	default:
		break;
	}
}

void DeleteCertainStudent(Student** mainListofStudents) {
	system("cls");
	char* targetName = (char*)CreateObject(MAX_LEN_OF_STRING);
	char* targetSurname = (char*)CreateObject(MAX_LEN_OF_STRING);
	Student* TargetStudent = (Student*)CreateObject(sizeof(Student));
	printf("Введите имя и фамилию нужного студента:\n");
	scanf_s("%s %s", targetName, MAX_LEN_OF_STRING, targetSurname, MAX_LEN_OF_STRING);
	Student** pStudent_1 = FindStudentByName(mainListofStudents, targetName);
	Student** pStudent_2 = FindStudentBySurname(mainListofStudents, targetSurname);
	for (int i = 0; pStudent_1[i] != NULL; i++) {
		for (int j = 0; pStudent_2[j] != NULL; j++) {
			if (pStudent_1[i] == pStudent_2[j]) {
				TargetStudent = pStudent_1[i];
			}
		}
	}
	int op = 0;
	printf("Что именно вы хотите сделать?\n1)Удалить студента\n2)Отчислить студента\n");
	scanf_s("%d", &op);
	if (op == 1)
		DeleteStudentFromList(mainListofStudents, &TargetStudent);
	else if (op == 2)
		ChangeState(TargetStudent, 2);
	else
		printf("Вывели что-то не так");
}

void DeleteAllStudent() {
	system("cls");
	for (int i = 0; ListofStudents[i] != NULL; i++) {
		DeleteStudent(ListofStudents[i]);
	}
	Student** tmp = (Student**)realloc(ListofStudents, sizeof(Student*));
	ListofStudents = tmp;
	if (!ListofStudents)
		exit(1);
	ListofStudents[0] = NULL;
	printf("Список очищен");
}

void AddNewStudent(Student** mainListofStudents) {
	system("cls");
	printf("Как вы хотите добавить студента?\n1) Через консоль\n2) Через файл\n");
	char* FilePath = (char*)CreateObject(MAX_LEN_OF_STRING * sizeof(char));
	if (!FilePath) {
		printf("xyi");
		return;
	}
	char action_case5 = '0';
	scanf_s(" %c", &action_case5, 1);
	switch (action_case5) {
	case '1':
		system("cls");
		printf("Введите данные студента, которого хотите добавить (имя, фамилия, дата рождения, дата поступления, статус обучения):\n");
		if (AddStudentFromConsole(mainListofStudents) == 1) {
			printf("Студент успешно добавлен!\n");
		}
		else {
			printf("Неверный ввод!");
		}
		break;
	case '2':
		system("cls");
		printf("Введите путь файла, с которого хотите считать студента:\n");
		scanf_s("%s", FilePath, MAX_LEN_OF_STRING);
		if (AddStudentFromFile(mainListofStudents, FilePath) == 1) {
			printf("Студент успешно добавлен!\n");
		}
		else {
			printf("Возможно, вы написали неправильный путь");
		}
		break;
	}
}

void SortList(Student** mainListofStudents) {
	system("cls");
	char op = '0';
	int N = CountOfStudent(mainListofStudents);
	printf("Как вы хотите отсортировать?\n1)имя\n2)Фамилия\n3)дата рождения\n");
	scanf_s(" %c", &op, 1);
	switch (op)
	{
	case '1':
		for (int i = 0; i < N; i++)
			for (int j = 0; j + 1 < N - i; j++)
				if (strcmp(mainListofStudents[j]->name, mainListofStudents[j+1]->name) > 0)
					Swap_Students(mainListofStudents[j], mainListofStudents[j+1]);
		break;
	case '2':
		for (int i = 0; i < N; i++)
			for (int j = 0; j + 1 < N - i; j++)
				if (strcmp(mainListofStudents[j]->surname, mainListofStudents[j+1]->surname) > 0)
					Swap_Students(mainListofStudents[j], mainListofStudents[j+1]);
		break;
	case '3':
		for (int i = 0; i < N; i++)
			for (int j = 0; j + 1< N - i; j++)
				if ((long long int)mainListofStudents[j]->Date_of_Birth > (long long int)mainListofStudents[j+1]->Date_of_Birth)
					Swap_Students(mainListofStudents[j], mainListofStudents[j+1]);
	default:
		break;
	}
}