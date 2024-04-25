#include <stdio.h>
#include <locale.h>

#define Div_On_Null		"Ошибка: вы делите число на ноль\n"
#define Not_Right_Value		"Ошибка: вы ввели не правильно пример\n"
#define Number_Is_Float	"Ошибка: вы ввели дробное число вместо целого\n"
#define Nod_Number_Is_Null "Ошибка: при вызыве функции NOD число(а) не должно(ы) быть равные ноль"

int ABS(int num) {
	return num < 0 ? -num : num;
}

float addition(float num_1, float num_2) {
	return num_1 + num_2;
}

float subtraction(float num_1, float num_2) {
	return num_1 - num_2;
}

float multiplication(float num_1, float num_2) {
	return num_1 * num_2;
}

float division(float num_1, float num_2) {
	return num_1 / num_2;
}

int remains(int num_1, int num_2) {
	return num_1 % num_2;
}

int NOD(int num_1, int num_2) {
	num_1 = ABS(num_1);
	num_2 = ABS(num_2);

	int dif = 0;
	int result;

	if (num_1 == num_2) {
		return num_1;
	}
	dif = num_1 - num_2;
	result = NOD(ABS(dif), num_1 < num_2 ? num_1 : num_2);
	return result;
}

void calc(float val_1, float val_2, char oper) {
	switch (oper)
	{
	case '+':
		if ((int)val_1 == val_1 && (int)val_2 == val_2)
			printf("%d", (int)addition(val_1, val_2));
		else
			printf("%.2f", addition(val_1, val_2));
		break;
	case '-':
		if ((int)val_1 == val_1 && (int)val_2 == val_2)
			printf("%d", (int)subtraction(val_1, val_2));
		else
			printf("%.2f", subtraction(val_1, val_2));
		break;
	case '*':
		if ((int)val_1 == val_1 && (int)val_2 == val_2)
			printf("%d", (int)multiplication(val_1, val_2));
		else {
			printf("%.2f", multiplication(val_1, val_2));
		}
		break;
	case '/':
		if (val_2 != 0) {
			if ((int)val_1 == val_1 && (int)val_2 == val_2)
				printf("%d", (int)division(val_1, val_2));
			else
				printf("%.2f", division(val_1, val_2));
		}
		else
			printf(Div_On_Null);
		break;
	case '%':
		if ((int)val_1 == val_1 && (int)val_2 == val_2)
			printf("%d", remains((int)val_1, (int)val_2));
		else
			printf(Number_Is_Float);
		break;
	case 'N':
		if (val_1 == 0 || val_2 == 0) {
			printf(Nod_Number_Is_Null);
		}
		else {
			if ((int)val_1 == val_1 && (int)val_2 == val_2)
				printf("%d", NOD((int)val_1, (int)val_2));
			else
				printf(Number_Is_Float);
		}
		break;
	default:
		printf(Not_Right_Value);
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");

	float var_1, var_2;
	char oper = '0';

	printf("Введите пример, подобный образцу:\n(первое число) (операция(+, -, *, /, %%, N(NOD))) (второе число)\n");
	scanf_s("%f %c %f", &var_1, &oper, 1, &var_2);

	calc(var_1, var_2, oper);
	
	return 0;
}