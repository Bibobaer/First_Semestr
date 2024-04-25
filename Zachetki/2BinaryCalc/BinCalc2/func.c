#include "func.h"

void sum_int_overflow(signed int a, signed int b) {
	if (((b > 0) && (a > (INT_MAX - b))) || ((b < 0) && (a < (INT_MIN - b)))) {
		printf(Bigger_Then_Max_Int);
		exit(1);
	}
}

void dif_int_overflow(signed int a, signed int b) {
	if ((b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b)) {
		printf(Bigger_Then_Max_Int);
		exit(1);
	}
}

void multi_int_overflow(signed int a, signed int b) {
	if (a > 0) {
		if (b > 0) {
			if (a > (INT_MAX / b)) {
				printf(Bigger_Then_Max_Int);
				exit(1);
			}
		}
		else {
			if (b < (INT_MIN / a)) {
				printf(Bigger_Then_Max_Int);
				exit(1);
			}
		}
	}
	else {
		if (b > 0) {
			if (a < (INT_MIN / b)) {
				printf(Bigger_Then_Max_Int);
				exit(1);
			}
		}
		else {
			if ((a != 0) && (b < (INT_MAX) / a)) {
				printf(Bigger_Then_Max_Int);
				exit(1);
			}
		}
	}
}

void Reverse_char_arr(char* arr, int n) {
	for (int i = 0; i < n / 2; ++i) {
		char tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}
void Reverse_int_arr(int* arr, int n) {
	for (int i = 0; i < n / 2; ++i) {
		int tmp = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = tmp;
	}
}

void Print_Qwart_Arr(int* arr, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d", arr[i - 1]);
		if (i % 4 == 0) {
			printf(" ");
		}
	}
	printf("\n");
}

void move_arr_right(int* arr, int bits) {
	Reverse_int_arr(arr, bits);
	for (int i = 0; i < bits-1; i++) {
		arr[i] = arr[i + 1];
	}
	arr[bits - 1] = 0;
	Reverse_int_arr(arr, bits);
}

void Is_Pow_Of_Two(int num) {
	if (num == 0) {
		printf(Num_is_Not_Pow_Of_Two);
		exit(1);
	}
	if (!(num & (num - 1)))
		return;
	else {
		printf(Num_is_Not_Pow_Of_Two);
		exit(1);
	}
}

int Is_Additional_Code(int* num_1, int bits) {
	int* minus_one = (int*)malloc(bits*sizeof(int));
	int* tmp = (int*)malloc(bits * sizeof(int));
	if (!minus_one || !tmp)
		exit(1);
	for (int j = 0; j < bits; j++) {
		minus_one[j] = 1;
		tmp[j] = 0;
	}
	tmp = plus(num_1, minus_one, bits);
	tmp = NOT(tmp, bits);
	if (tmp == num_1)
		return 1;
	return 0;

}

int unknow_to_dec(int cc, char* mas) {
	if (cc < 2) {
		printf(CC_Smaller_Then_Two);
		exit(1);
	}
	int sum = 0;
	int len = (int)strlen(mas);
	int tmp = *mas == '-' ? len - 2 : len - 1;
	int i = *mas == '-' ? 1 : 0;
	for (; i < len; i++) {
		if (mas[i] <= '9' && mas[i] >= '0') {
			if (mas[i] - 48 >= cc) {
				printf(Numbers_in_String_Bigger_Then_CC);
				exit(1);
			}
			sum_int_overflow(sum, ((mas[i] - 48) * (int)pow(cc, tmp)));
			sum += ((mas[i] - 48) * (int)pow(cc, tmp));
			tmp--;
		}
		else {
			if (mas[i] <= 'Z' && mas[i] >= 'A') {
				if (mas[i] - 55 > cc) {
					printf(Numbers_in_String_Bigger_Then_CC);
					exit(1);
				}
				sum_int_overflow(sum, ((mas[i] - 55) * (int)pow(cc, tmp)));
				sum += ((mas[i] - 55) * (int)pow(cc, tmp));
				tmp--;
			}
			else {
				if (mas[i] - 61 > cc) {
					printf(Numbers_in_String_Bigger_Then_CC);
					exit(1);
				}
				sum_int_overflow(sum, ((mas[i] - 61) * (int)pow(cc, tmp)));
				sum += ((mas[i] - 61) * (int)pow(cc, tmp));
				tmp--;
			}
		}
	}
	sum = *mas == '-' ? -sum : sum;
	free(mas);
	return sum;
}
void dec_to_bin(int num, int bits, int* mas) {
	int i = 0;
	for (int j = 0; j < bits; ++j)
		mas[j] = 0;

	if (num < 0) {
		num = abs(num) - 1;
		while (num)
		{
			if (i > bits) {
				printf(Big_Bin_Num);
				exit(1);
			}
			*(mas + i) = num % 2;
			num /= 2;
			i++;

		}
		for (int m = 0; m < bits; m++) {
			if (mas[m] == 1)
				mas[m] = 0;
			else
				mas[m] = 1;
		}
		Reverse_int_arr(mas, bits);
		*mas = 1;
	}
	else {
		while (num)
		{
			if (i > bits) {
				printf(Big_Bin_Num);
				exit(1);
			}
			*(mas + i) = num % 2;
			num /= 2;
			i++;

		}

		Reverse_int_arr(mas, bits);
	}
}

char* dec_to_hex(int num, char* arr) {
	int i = 0, temp;
	int j;
	for (int k = 0; k < MAX_LEN_STRING; k++) {
		arr[k] = 0;
	}

	if (num < 0) {
		j = 1;
		num = abs(num);
		while (num) {
			temp = num % 16;
			if (temp < 10)
				temp += 48;
			else
				temp += 55;
			arr[i++] = temp;
			num /= 16;
			j++;
		}
		Reverse_char_arr(arr, j);
		arr[0] = '-';
	}
	else {
		j = 0;
		while (num) {
			temp = num % 16;
			if (temp < 10)
				temp = temp + 48;
			else
				temp = temp + 55;
			arr[i++] = temp;
			num /= 16;
			j++;
		}
		Reverse_char_arr(arr, j);
	}
	return arr;
}

int* bin_calc(int* num_1, int* num_2, char* oper, int bits, int num_1_in_dec, int num_2_in_dec, int dec_res, char* hex_res) {
	int tmp;
	char op;
	if (!strcmp(oper, "AND") || !strcmp(oper, "and"))
		op = 'A';
	else if (!strcmp(oper, "NOT") || !strcmp(oper, "not"))
		op = 'N';
	else if (!strcmp(oper, "OR") || !strcmp(oper, "or"))
		op = 'O';
	else if (!strcmp(oper, "XNOR") || !strcmp(oper, "xnor"))
		op = 'x';
	else if (!strcmp(oper, "XOR") || !strcmp(oper, "xor"))
		op = 'X';
	else if (!strcmp(oper, "IMP") || !strcmp(oper, "imp"))
		op = 'I';
	else if (!strcmp(oper, "NIMP") || !strcmp(oper, "nimp"))
		op = 'i';
	else if (!strcmp(oper, "NAND") || !strcmp(oper, "nand"))
		op = 'a';
	else if (!strcmp(oper, "NOR") || !strcmp(oper, "nor"))
		op = 'o';
	else {
		printf(Not_Right_Op_in_Calc);
		exit(1);
	}

	switch (op)
	{
	case 'N':
		puts("Какое число вы хотите инвертировать?(введите 1 или 2)");
		scanf_s("%d", &tmp);
		if (tmp == 1) {
			dec_res = ~num_1_in_dec;
			printf("%d\n", dec_res);
			dec_to_hex(dec_res, hex_res);
			printf("hex: %s\n", hex_res);
			return NOT(num_1, bits);
		}
		else if (tmp == 2) {
			dec_res = ~num_2_in_dec;
			printf("%d\n", dec_res);
			dec_to_hex(dec_res, hex_res);
			printf("hex: %s\n", hex_res);
			return NOT(num_2, bits);
		}
		else {
			printf(Not_Right_Op_in_Calc);
			exit(1);
		}
		break;
	case 'A':
		dec_res = num_1_in_dec & num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return AND(num_1, num_2, bits);
		break;
	case 'O':
		dec_res = num_1_in_dec | num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return OR(num_1, num_2, bits);
		break;
	case 'X':
		dec_res = num_1_in_dec ^ num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return XOR(num_1, num_2, bits);
		break;
	case 'x':
		dec_res = ~(num_1_in_dec ^ num_2_in_dec);
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return XNOR(num_1, num_2, bits);
		break;
	case 'I':
		dec_res = (~num_1_in_dec) | num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return IMPL(num_1, num_2, bits);
		break;
	case 'i':
		dec_res = num_1_in_dec & (~num_2_in_dec);
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return NOT_IMPL(num_1, num_2, bits);
		break;
	case 'a':
		dec_res = ~(num_1_in_dec & num_2_in_dec);
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return NOT_AND(num_1, num_2, bits);
		break;
	case 'o':
		dec_res = ~(num_1_in_dec | num_2_in_dec);
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		return NOT_OR(num_1, num_2, bits);
		break;
	default:
		printf(Not_Right_Op_in_Calc);
		break;
	}
	return 0;
}

int* dec_calc(int* num_1, int* num_2, char oper, int bits, int num_1_in_dec, int num_2_in_dec, int dec_res, char* hex_res) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int i = 0; i < bits; i++)
		res[i] = 0;
	switch (oper)
	{
	case '+':
		dec_res = num_1_in_dec + num_2_in_dec;
		if (dec_res > (int)pow(2, bits - 1) - 1) {
			dec_res = -(dec_res+1) + num_2_in_dec;
		}
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		res = plus(num_1, num_2, bits);
		return res;
		break;
	case '-':
		dec_res = num_1_in_dec - num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		res = minus(num_1, num_2, bits);
		return res;
		break;
	case '*':
		dec_res = num_1_in_dec * num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		res = multi(num_1, num_2, bits);
		return res;
		break;
	case '/':
		dec_res = num_1_in_dec / num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		res = divi(num_1, num_2, bits, num_1_in_dec, num_2_in_dec);
		return res;
		break;
	case '%':
		dec_res = num_1_in_dec % num_2_in_dec;
		printf("dec: %d\n", dec_res);
		dec_to_hex(dec_res, hex_res);
		printf("hex: %s\n", hex_res);
		res = ostat(num_1, num_2, bits, num_1_in_dec, num_2_in_dec);
		return res;
		break;
	default:
		printf(Not_Right_Op_in_Calc);
		break;
	}
	return 0;
}