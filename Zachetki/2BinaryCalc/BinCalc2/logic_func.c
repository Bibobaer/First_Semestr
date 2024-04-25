#include "logic_func.h"
#include "func.h"

int* NOT(int* num, int bits) {
	for (int i = 0; i < bits; i++) {
		if (num[i] == 0) {
			num[i] = 1;
		}
		else {
			num[i] = 0;
		}
	}
	return num;
}

int* AND(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits*sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;

	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 0;
		else if ((num_1[i] == 1 && num_2[i] == 0) || (num_1[i] == 0 && num_2[i] == 1))
			res[i] = 0;
		else
			res[i] = 1;
	}
	return res;
}
int* OR(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;

	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 0;
		else if ((num_1[i] == 1 && num_2[i] == 0) || (num_1[i] == 0 && num_2[i] == 1))
			res[i] = 1;
		else
			res[i] = 1;
	}
	return res;
}
int* XNOR(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 1;
		else if ((num_1[i] == 1 && num_2[i] == 0) || (num_1[i] == 0 && num_2[i] == 1))
			res[i] = 0;
		else
			res[i] = 1;
	}
	return res;
}
int* XOR(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 0;
		else if ((num_1[i] == 1 && num_2[i] == 0) || (num_1[i] == 0 && num_2[i] == 1))
			res[i] = 1;
		else
			res[i] = 0;
	}
	return res;
}
int* IMPL(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 1;
		else if ((num_1[i] == 1 && num_2[i] == 0))
			res[i] = 0;
		else if ((num_1[i] == 0 && num_2[i] == 1)) {
			res[i] = 1;
		}
		else
			res[i] = 1;
	}
	return res;
}
int* NOT_IMPL(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 0;
		else if ((num_1[i] == 1 && num_2[i] == 0))
			res[i] = 1;
		else if ((num_1[i] == 0 && num_2[i] == 1))
			res[i] = 0;
		else
			res[i] = 0;
	}
	return res;
}
int* NOT_AND(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;
	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 1;
		else if ((num_1[i] == 1 && num_2[i] == 0) || (num_1[i] == 0 && num_2[i] == 1))
			res[i] = 1;
		else
			res[i] = 0;
	}
	return res;
}
int* NOT_OR(int* num_1, int* num_2, int bits) {
	int* res = (int*)malloc(bits * sizeof(int));
	if (!res)
		exit(1);
	for (int j = 0; j < bits; j++)
		res[j] = 0;

	for (int i = 0; i < bits; i++) {
		if (num_1[i] == 0 && num_2[i] == 0)
			res[i] = 1;
		else if ((num_1[i] == 1 && num_2[i] == 0) || (num_1[i] == 0 && num_2[i] == 1))
			res[i] = 0;
		else
			res[i] = 0;
	}
	return res;
}