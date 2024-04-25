#include "func.h"

int main() {
	setlocale(LC_ALL, "Rus");
	int cc_1 = 0, cc_2 = 0;
	int bits = 0;
	char AorL = '0';
	char oper = '0';
	char* logic_oper = (char*)malloc(MAX_LEN_LOG_OPERETION * sizeof(char));

	char* str_1 = (char*)malloc(MAX_LEN_STRING * sizeof(char));
	char* str_2 = (char*)malloc(MAX_LEN_STRING * sizeof(char));

	if (!str_1 || !str_2) {
		printf("error");
		exit(1);
	}

	printf("Введите систему счисления первого числа(желательно до 36): ");
	scanf_s("%d", &cc_1);

	printf("Введите первое число в этой системе: ");
	scanf_s("%s", str_1, MAX_LEN_STRING);

	int num_1_in_dec = unknow_to_dec(cc_1, str_1);
	int* num_1 = (int*)malloc(bits * sizeof(int));

	printf("Введите систему счисления второго числа(желательно до 36): ");
	scanf_s("%d", &cc_2);

	printf("Введите второго число в этой системе: ");
	scanf_s("%s", str_2, MAX_LEN_STRING);

	int num_2_in_dec = unknow_to_dec(cc_2, str_2);
	int* num_2 = (int*)malloc(bits * sizeof(int));

	printf("Введите разрадность чисел(степень двойки): ");
	scanf_s("%d", &bits);
	Is_Pow_Of_Two(bits);

	printf_s("Какие операции хотите произвести арифметические(A) или логические(L)?\n");
	scanf_s(" %c", &AorL, 1);
	
	int dec_res = 0;
	int* res = (int*)malloc(bits * sizeof(int));

	char* hex_res = (char*)malloc(MAX_LEN_STRING*sizeof(char));

	if (!num_1 || !num_2 || !res || !hex_res)
		exit(1);
	dec_to_bin(num_1_in_dec, bits, num_1);
	dec_to_bin(num_2_in_dec, bits, num_2);

	if (AorL == 'A' || AorL == 'a') {
		printf("Какую операцию хотите сделать? (+,-,*,/,%%): ");
		scanf_s(" %c", &oper, 1);
		printf("Введённые числа в двоичке\n");
		Print_Qwart_Arr(num_1, bits);
		Print_Qwart_Arr(num_2, bits);
		printf("Результат:\n");
		res = dec_calc(num_1, num_2, oper, bits, num_1_in_dec, num_2_in_dec, dec_res, hex_res);
		printf("bin: ");
		Print_Qwart_Arr(res, bits);
	}
	else if (AorL == 'L' || AorL == 'l') {
		printf("Какую операцию хотите сделать? (NOT, AND, OR, XNOR, XOR, IMP, NAND, NOR, NIMP): ");
		scanf_s("%s", logic_oper, MAX_LEN_LOG_OPERETION);
		printf("Введённые числа в двоичке\n");
		Print_Qwart_Arr(num_1, bits);
		Print_Qwart_Arr(num_2, bits);
		printf("Результат:\n");
		res = bin_calc(num_1, num_2, logic_oper, bits, num_1_in_dec, num_2_in_dec, dec_res, hex_res);
		printf("bin: ");
		Print_Qwart_Arr(res, bits);
	}
	else {
		printf(Not_Right_Op_in_Calc);
		exit(1);
	}
	return 0;
}