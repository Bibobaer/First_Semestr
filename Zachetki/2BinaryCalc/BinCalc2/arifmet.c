#include "func.h"
#include "arifmet.h"

int* plus(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
    if (!res)
        exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	for (int i = 1; i <= bits; i++) {
		res[bits - i] = num_1[bits - i] + num_2[bits - i];
	}
	for (int i = 1; i <= bits - 1; i++) {
		if (res[bits - i] >= 2) {
			res[bits - i - 1] = res[bits - i - 1] + res[bits - i] / 2;
			res[bits - i] = res[bits - i] % 2;
		}
	}
	if (*res == 2)
		*res = 0;
	else if (*res == 3)
		*res = 1;
	return res;
}
int* minus(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;

	if (Is_Additional_Code(num_2, bits) == 0) {
		int* plus_one = (int*)malloc(bits * sizeof(int));
		if (!plus_one)
			exit(1);
		for (int j = 0; j < bits; j++) {
			plus_one[j] = 0;
		}
		plus_one[bits - 1] = 1;
		num_2 = NOT(num_2, bits);
		num_2 = plus(num_2, plus_one, bits);
		res = plus(num_1, num_2, bits);
		free(plus_one);
	}

	else {
		res = plus(num_1, num_2, bits);
	}
	if (*res == 2)
		*res = 0;
	else if (*res == 3)
		*res = 1;
	return res;
}
int* multi(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int i = 0; i < bits; i++)
		res[i] = 0;
	for (int i = 0; i < bits; i++) {
		for (int j = 0; j < bits; j++) {
			res[bits - i - j - 1] += (num_1[bits - i - 1] * num_2[bits - j - 1]);
		}
	}
	for (int i = 1; i <= bits - 1; i++) {
		if (res[bits - i] >= 2) {
			res[bits - i - 1] = res[bits - i - 1] + res[bits - i] / 2;
			res[bits - i] = res[bits - i] % 2;
		}
	}
	if (*res > 1)
		*res = 1;
	return res;
}
int* divi(int* num_1, int* num_2, int bits, int num_1_in_dec, int num_2_in_dec) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++) {
		res[j] = 0;
	}
	
	while (num_1_in_dec > num_2_in_dec) {
		for (int i = 0; i < bits; i++) {
			num_1 = minus(num_1, num_2, bits);
			num_1_in_dec -= num_2_in_dec;
		}
		move_arr_right(num_1, bits);
	}
	res = num_1;
	return res;
}

int* ostat(int* num_1, int* num_2, int bits, int n1_dec, int n2_dec) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	while (n1_dec >= n2_dec) {
		num_1 = minus(num_1, num_2, bits);
		n1_dec -= n2_dec;
	}
	res = num_1;
	return res;
}