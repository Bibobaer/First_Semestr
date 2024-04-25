#include <stdio.h>
#include <locale.h>
#include <conio.h>

typedef struct{
	int Real;
	int Image;
}Complex_Number;

Complex_Number Calc(Complex_Number Num_1, Complex_Number Num_2, char op) {
	Complex_Number Result = {0, 0};
	switch (op)
	{
	case '+':
		Result.Real = Num_1.Real + Num_2.Real;
		Result.Image = Num_1.Image + Num_2.Image;
		break;
	case '-':
		Result.Real = Num_1.Real - Num_2.Real;
		Result.Image = Num_1.Image - Num_2.Image;
		break;
	case '*':
		Result.Real = Num_1.Real * Num_2.Real - Num_1.Image * Num_2.Image;
		Result.Image = Num_1.Real * Num_2.Image + Num_1.Image * Num_2.Real;
		break;
	default:
		printf("вы ввели не правильную операцию");
		break;
	}
	return Result;
}

int main() {
	setlocale(LC_ALL, "Rus");
	Complex_Number first_number;
	Complex_Number second_number;
	Complex_Number Result;
	char oper;
	printf("¬ведите пример, как в примере\n(R1, I1) операци€ (R2, I2)\n");
	scanf_s("(%d, %d) %c (%d, %d)", &first_number.Real, &first_number.Image, &oper, 1, &second_number.Real, &second_number.Image);
	Result = Calc(first_number, second_number, oper);
	printf("(%d, %d)\n", Result.Real, Result.Image);

	_getch();
	return 0;
}